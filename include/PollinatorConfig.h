/**
 * @file
 *
 * Declaration of the PollinatorConfig class
 */

#ifndef _POLLINATORCONFIG_H
#define _POLLINATORCONFIG_H

#include <string>
#include "PollinatorConstancyType.h"
#include "ReflectanceInfo.h"

/**
 * The PollinatorConfig class ...
 */
struct PollinatorConfig {
    PollinatorConfig() {};

    std::string species;
    int boutLength;
    int maxPollenCapacity;
    int pollenDepositPerFlowerVisit;
    int pollenLossInAir;
    int pollenCarryoverNumVisits;
    MarkerPoint innateMPPrefMin;
    MarkerPoint innateMPPrefMax;
    std::string strConstancyType;
    PollinatorConstancyType constancyType;
    float constancyParam;
};

#endif /* _POLLINATORCONFIG_H */
