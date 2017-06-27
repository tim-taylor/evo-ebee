/**
 * @file
 *
 * Implementation of the Pollinator class
 */

#include <cmath>
#include <random>
#include <cassert>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include "EvoBeeModel.h"
#include "PollinatorConfig.h"
#include "Pollinator.h"

constexpr double PI = 4.0*std::atan(1);
constexpr double TWOPI = 2.0*PI;

unsigned int Pollinator::m_sNextFreeId = 1;
std::string Pollinator::m_sTypeNameStr{"POL"};
std::uniform_real_distribution<float> Pollinator::m_sDirectionDistrib(0.0, TWOPI);


Pollinator::Pollinator(const PollinatorConfig& pc, AbstractHive* pHive) :
    m_id(m_sNextFreeId++),
    m_pHive(pHive),
    m_State(PollinatorState::UNINITIATED),
    m_iNumFlowersVisitedInBout(0),
    m_iBoutLength(pc.boutLength),
    m_iPollenLossOnFlower(pc.pollenLossOnFlower),
    m_iPollenLossInAir(pc.pollenLossInAir),
    m_iMaxPollenCapacity(pc.maxPollenCapacity),
    m_iPollenCarryoverNumVisits(pc.pollenCarryoverNumVisits)
{
    // Set the starting position and heading of the pollinator
    resetToStartPosition();

    // Each pollinator has a pointer to the environment and to the model for 
    // convenience, to save having to ask the Hive for these each time we need them
    m_pEnv = m_pHive->getEnvironment();
    m_pModel = m_pEnv->getModel();
}


void Pollinator::reset()
{
    m_State = PollinatorState::UNINITIATED;
    m_iNumFlowersVisitedInBout = 0;
    m_PollenStore.clear();
    resetToStartPosition();
}


void Pollinator::resetToStartPosition()
{
    m_fHeading = m_sDirectionDistrib(EvoBeeModel::m_sRngEngine);

    if (m_pHive->startFromHive())
    {
        m_Position = m_pHive->getPosition();
    }
    else
    {
        m_Position = m_pHive->getRandomPollinatorStartPosition();
    }
}


bool Pollinator::inAllowedArea() const
{
    bool ok = true;
    if (m_pHive->migrationAllowed())
    {
        ok = inEnvironment();
    }
    else
    {
        const iPos& TL = m_pHive->getInitForageAreaTopLeft();
        const iPos& BR = m_pHive->getInitForageAreaBottomRight();
        ok = ((m_Position.x >= (float)TL.x) &&
              (m_Position.x <  (float)(BR.x+1)) &&
              (m_Position.y >= (float)TL.y) &&
              (m_Position.y <  (float)(BR.y+1)));
    }
    return ok;
}


// A helper method for the move... methods for use when a pollinator has
// wandered off the environment. Reflect the movement off the edge of
// the environment and reposition the pollinator back within the allowed
// area
void Pollinator::repositionInEnv(fPos delta)
{
    repositionInArea(delta, 0.0, 0.0, m_pEnv->getSizeXf(), m_pEnv->getSizeYf());
    assert(inEnvironment());
}


// A helper method for the move... methods for use when a pollinator has
// wandered out of its allowed area. Reflect the movement off the edge of
// the environment and reposition the pollinator back within the allowed
// area
void Pollinator::repositionInAllowedArea(fPos delta)
{
    const iPos& TL = m_pHive->getInitForageAreaTopLeft();
    const iPos& BR = m_pHive->getInitForageAreaBottomRight();    
    repositionInArea(delta, (float)TL.x, (float)TL.y, (float)(BR.x+1), (float)(BR.y+1));
    assert(inEnvironment());
}


// A helper method for the move... methods for use when a pollinator has
// wandered out of the specified area. Reflect the movement off the edge of
// the environment and reposition the pollinator back within the allowed
// area
void Pollinator::repositionInArea(fPos delta, float minx, float miny, float maxx, float maxy)
{
    fPos oldPos = m_Position - delta;

    if (m_Position.x < minx || m_Position.x >= maxx)
    {
        delta.x = -delta.x;
    }

    if (m_Position.y < miny || m_Position.y >= maxy)
    {
        delta.y = -delta.y;
    }

    m_Position = oldPos + delta;   
}


// Move by a given distance in a random direction. 
//
// @todo Maybe implement a "stay/hover" option in future?
//
void Pollinator::moveRandom(/*bool allowOffEnv,*/ float stepLength)
{
    m_fHeading = m_sDirectionDistrib(EvoBeeModel::m_sRngEngine);

    fPos delta{stepLength*std::cos(m_fHeading), stepLength*std::sin(m_fHeading)};
    m_Position += delta;

    if (!inAllowedArea())
    {
        repositionInAllowedArea(delta);
    }
}


bool Pollinator::moveBiassed(bool allowOffEnv, float stepLength)
{
    ///@todo implement moveBiassed
    fPos delta;

    bool inEnv = inEnvironment();

    if (!inEnv && !allowOffEnv)
    {
        repositionInEnv(delta);
    }

    return inEnv;    
}


bool Pollinator::moveLevy(bool allowOffEnv, float stepLength)
{
    ///@todo implement moveLevy
    fPos delta;

    bool inEnv = inEnvironment();

    if (!inEnv && !allowOffEnv)
    {
        repositionInEnv(delta);
    }

    return inEnv;    
}


// for each Pollen grain in the store, update its landing count
void Pollinator::updatePollenLandingCount()
{
    std::for_each(m_PollenStore.begin(), 
                  m_PollenStore.end(),
                  [](Pollen& p){p.numLandings++;}
    );
}


// Remove any pollen from the store that has exceeded m_iPollenCarryoverNumVisits
void Pollinator::removeOldCarryoverPollen()
{
    // test code
    //size_t oldsz = m_PollenStore.size();

    m_PollenStore.erase(
        std::remove_if(m_PollenStore.begin(),
                       m_PollenStore.end(),
                       [this](Pollen& p) {return (p.numLandings > m_iPollenCarryoverNumVisits);}),
        m_PollenStore.end()
    );

    /// test code
    //size_t newsz = m_PollenStore.size();
    //if (newsz != oldsz) std::cout << "carryover removed! " << oldsz << "->" << newsz << std::endl;
}


// Transfer some of our pollen to the flower (potentially pollinating it)
int Pollinator::depositPollenOnStigma(Flower* pFlower)
{
    return pFlower->transferPollenFromPollinator(m_PollenStore, m_iPollenLossOnFlower);
}


// Collect pollen from flower if available, and add to our store
// If any pollen is added, the contents of the store is shuffled so that
// subsequent operations that act of randomly chosen grains from the store
// can simply and efficiently pick off grains from the end of the store.
// If the store's maxium capacity is exceeded, some random grains are
// removed to bring it down to the maximum allowed size.
//
void Pollinator::collectPollenFromAnther(Flower* pFlower)
{
    // transfer anther pollen from flower to our store
    int num = pFlower->transferAntherPollenToPollinator(m_PollenStore);

    // if some new grains have been added, shuffle the whole store now
    // so that subsequent removals of pollen happen in a random order
    if (num > 0)
    {
        std::shuffle(m_PollenStore.begin(), m_PollenStore.end(), EvoBeeModel::m_sRngEngine);
    }

    // finally, if the number of grains in our store now exceeds the
    // maximum capacity, delete some. As we've just shuffled the store,
    // we can just remove the required number from the end of the store
    int xs = m_PollenStore.size() - m_iMaxPollenCapacity;
    if (xs > 0)
    {
        m_PollenStore.erase(m_PollenStore.end()-xs, m_PollenStore.end());
    }
}


// Lose the specified amount of pollen to the air
int Pollinator::losePollenToAir(int num)
{
    num = std::min(num, (int)m_PollenStore.size());
    m_PollenStore.erase(m_PollenStore.end()-num, m_PollenStore.end());
    return num;
}


std::string Pollinator::getStateString() const
{
    std::stringstream ssState;
    ssState << std::fixed << std::setprecision(3) << getTypeName() << ","
        << m_id << "," << m_Position.x << "," << m_Position.y << "," << m_fHeading;
    return ssState.str();
}


const std::string& Pollinator::getTypeName() const
{
    return m_sTypeNameStr;
} 