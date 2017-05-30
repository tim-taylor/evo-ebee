/**
 * @file
 *
 * Implementation of the Environment class
 */

#include <cassert>
#include <vector>
#include <iostream>
#include <memory>
#include <random>
#include "ModelParams.h"
#include "EvoBeeModel.h"
#include "Patch.h"
#include "Colour.h"
#include "AbstractHive.h"
#include "Hive.h"
#include "HoneyBee.h"
#include "Position.h"
#include "Environment.h"

using std::cout;
using std::endl;


Environment::Environment() 
{
    assert(ModelParams::initialised());

    // Initialise Patches
    m_iNumPatches = ModelParams::getNumPatches();
    m_Patches.reserve(m_iNumPatches);
    for (int i = 0; i < m_iNumPatches; ++i) 
    {
        m_Patches.push_back(
            Patch(this, i, 
                //ModelParams::getEnvDefaultBackgroundColour(),
                ModelParams::getEnvBackgroundReflectanceMP(),
                ModelParams::getEnvDefaultAmbientTemp()
            )
        );
    }

    // Initialise Hives
    const std::vector<HiveConfig> & hconfigs = ModelParams::getHiveConfigs();
    for (const HiveConfig& hconfig : hconfigs)
    {
        // Use the AbstractHive::makeHive factory method to make a Hive of the right type
        m_Hives.push_back( AbstractHive::makeHive(this, hconfig) );
    }

    // Initialise Plants
    initialisePlants();

    cout << "Initialised Environment with " << m_Patches.size() << " patches" << endl;    
}


iPos Environment::getPatchCoordsFromIdx(int idx)
{
    assert(idx >= 0);
    assert(idx < m_iNumPatches);
    return iPos(idx % ModelParams::getEnvSizeX(), idx / ModelParams::getEnvSizeX());
}


Patch& Environment::getPatch(int x, int y)
{
    int idx = x + (ModelParams::getEnvSizeX() * y);

    assert(idx >= 0);
    assert(idx < m_iNumPatches);

    return m_Patches[idx];
}


/**
 * This is a private helper method called by the constructor.
 *
 * It creates the required number and distribution of plants as specified in the config file
 */
void Environment::initialisePlants()
{
    const std::vector<PlantTypeDistributionConfig> &pdconfigs = ModelParams::getPlantTypeDistributionConfigs();
    for (const PlantTypeDistributionConfig &pdcfg : pdconfigs)
    {
        // first find the corresponding PlantTypeConfig
        const PlantTypeConfig* pPTC = ModelParams::getPlantTypeConfig(pdcfg.species);
        if (pPTC == nullptr)
        {
            throw std::runtime_error("Unknown plant species '" + pdcfg.species + "' specified in config file");
        }

        // calculate some basic values associated with the requested distribution
        int w = std::max(1, 1 + pdcfg.areaBottomRightX - pdcfg.areaTopLeftX);
        int h = std::max(1, 1 + pdcfg.areaBottomRightY - pdcfg.areaTopLeftY);
        int area = w * h;
        int numPlants = (int)((float)area * pdcfg.density);
        std::uniform_real_distribution<float> distW(0.0, w);
        std::uniform_real_distribution<float> distH(0.0, h);

        // create a 2D array that will record, for each patch in the distribution area,
        // the coordinates of each plant to be added to that patch
        std::vector<fPos> patchInfo[w][h];

        for (int i = 0; i < numPlants; ++i)
        {
            fPos fpos{ pdcfg.areaTopLeftX + distW(EvoBeeModel::m_sRngEngine),
                       pdcfg.areaTopLeftY + distH(EvoBeeModel::m_sRngEngine) };
            int iLocalX = (int)fpos.x - pdcfg.areaTopLeftX;
            int iLocalY = (int)fpos.y - pdcfg.areaTopLeftY;
            patchInfo[iLocalX][iLocalY].push_back(fpos);
        }

        // now go through the patchInfo array, and for each patch, go through all plants
        // to be added to that patch
        for (int x = 0; x < w; ++x)
        {
            for (int y = 0; y < h; ++y)
            {
                Patch &p = getPatch(x + pdcfg.areaTopLeftX, y + pdcfg.areaTopLeftY);
                auto &v = patchInfo[x][y];
                for (auto &pinfo : v)
                {
                    // pinfo.first is x coordinate, second is y coordinate
                    p.addPlant(*pPTC, pinfo);
                }
            }
        }
    }
}


fPos Environment::getRandomPositionF() const
{
    static std::uniform_real_distribution<float> distX(0.0, (float)ModelParams::getEnvSizeX());
    static std::uniform_real_distribution<float> distY(0.0, (float)ModelParams::getEnvSizeY());
    return fPos(distX(EvoBeeModel::m_sRngEngine), distY(EvoBeeModel::m_sRngEngine));
}