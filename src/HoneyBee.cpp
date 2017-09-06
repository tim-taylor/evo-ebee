/**
 * @file
 *
 * Implementation of the HoneyBee class
 */

#include <iostream>
#include <exception>
#include "FloweringPlant.h"
#include "Environment.h"
#include "ModelParams.h"
#include "Flower.h"
#include "HoneyBee.h"

std::string HoneyBee::m_sTypeNameStr{"HNB"};


HoneyBee::HoneyBee(const PollinatorConfig& pc, AbstractHive* pHive) :
    Hymenoptera(pc, pHive)
{
}

HoneyBee::HoneyBee(const HoneyBee& other) :
    Hymenoptera(other)
{
}

HoneyBee::HoneyBee(HoneyBee&& other) noexcept :
    Hymenoptera(std::move(other))
{
}

void HoneyBee::reset()
{
    Hymenoptera::reset();
}


/*
void HoneyBee::step()
{
    switch (m_State)
    {
        case (PollinatorState::UNINITIATED):
        {
            m_State = PollinatorState::FORAGING;
            // and now fall through to next case
        }
        case (PollinatorState::FORAGING):
        {
            switch (m_ForagingStrategy)
            {
                case (PollinatorForagingStrategy::RANDOM):
                {
                    forageRandom();
                    break;
                }
                case (PollinatorForagingStrategy::NEAREST_FLOWER):
                {
                    forageNearestFlower();
                    break;
                }
                default:
                {
                    throw std::runtime_error("Unknown pollinator foraging strategy encountered");
                }
            }
        }
        case (PollinatorState::BOUT_COMPLETE):
        {
            // (do nothing)
            break;
        }
        default:
        {
            throw std::runtime_error("Unknown pollinator state encountered");
        }

    }
}
*/

/*
void HoneyBee::visitFlower(Flower* pFlower)
{
    // for each Pollen grain in the store, update its landing count
    updatePollenLandingCount();

    // remove pollen from store that is now past the carryover limit
    removeOldCarryoverPollen();

    // first transfer some of bee's pollen to the flower (potentially pollinating it)
    depositPollenOnStigma(pFlower);

    // now pick up more pollen from the flower
    collectPollenFromAnther(pFlower);

    // update record of most recent landing to this one
    m_PreviousLandingSpeciesId = pFlower->getSpeciesId();

    // update count of number of flowers visited, and end bout if done
    if (++m_iNumFlowersVisitedInBout >= m_iBoutLength)
    {
        m_State = PollinatorState::BOUT_COMPLETE;
    }
}
*/

/*
bool HoneyBee::isVisitCandidate(Flower* pFlower) const
{
    bool bOfInterest = true;

    if (m_ConstancyType == PollinatorConstancyType::SIMPLE)
    {
        // take into account the type of the previous flower visited, and the probability
        // of landing on the same type this time around...

        if (m_PreviousLandingSpeciesId == 0)
        {
            // have not landed on a flower previously, so we'll land on this one
            // whatever!
            bOfInterest = true;
        }
        else
        {
            // consider whether this flower is of the same species as the previous one
            float prob = (m_PreviousLandingSpeciesId == pFlower->getSpeciesId()) ?
                m_fConstancyParam : (1.0 - m_fConstancyParam);

            bOfInterest = (EvoBeeModel::m_sUniformProbDistrib(EvoBeeModel::m_sRngEngine) < prob);
        }
    }



    ///@todo - implement isVisitCandidate based upon innate and learned preferences for flower colour

    / **
    // from Zoe's code...

    //Ensusre that is it more likely to harvest this flower if it is the right colour/is favoured, and vice versa.

    Flower flower = field.getFlowerAtLocation(row,col);			//The flower in question
    Flower.FlowerType type = flower.getType();				//Its type
    double sensitivity = flowerTypeSensitivity.get(type);			//Sensitivity to this flowers colour
    double currentLearnedPreference = flowerTypeLearnedPreference.get(type);//And this bee's currrent preference for it

    if(Math.random() < (sensitivity + currentLearnedPreference)) //(Math.random() < field.getFlowerAtLocation(row,col).getHymSensitivity())
    {
        harvest = true;
        //TRIAL updateLearnedPreferences(type);	//If it lands here increase it preference for this flower
        //System.out.printf("YES!"+flowerTypeLearnedPreference);

    }
    else
    {
        //System.out.printf("NOPE!"); 	//Don't touch the preferences if not harvesting
    }
    ** /

    return bOfInterest;
}
*/

std::string HoneyBee::getStateString() const
{
    return Hymenoptera::getStateString();
}


const std::string& HoneyBee::getTypeName() const
{
    return m_sTypeNameStr;
}
