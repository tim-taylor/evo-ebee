/**
 * @file
 *
 * Declaration of the Hymenoptera class
 */

#ifndef _HYMENOPTERA_H
#define _HYMENOPTERA_H

#include <string>
#include "PollinatorConfig.h"
#include "Pollinator.h"


/**
 * The Hymenoptera class ...
 */
class Hymenoptera : public Pollinator {

public:
    Hymenoptera(const PollinatorConfig& pc, AbstractHive* pHive);
    ~Hymenoptera() {}

    Hymenoptera(const Hymenoptera& other);
    Hymenoptera(Hymenoptera&& other) noexcept;

    void reset() override;

    //void step() override = 0;

    std::string getStateString() const override;

    const std::string& getTypeName() const override;

protected:
    /**
     * Returns the probability that this pollinator detects a visual stimulus which
     * possesses a single marker point as specified by the mp parameter.
     *
     * @return Detection probablility in the range 0.0 to 1.0
     */
    float getMPDetectionProb(MarkerPoint mp) const override;

    /**
     * Returns information about how a given stimulus with a single marker point
     * as specified by the mp parameter is perceived by this pollinator's visual
     * system.
     *
     * @return A const reference to a VisHexInfo which specifies the stimulus's
     * location in hexagonal colour space, its green contrast, and detection probability
     */
    const VisualStimulusInfo& getVisStimulusInfo(MarkerPoint mp) const override;

    /**
     * Returns information about the pollinator's current preferences for
     * a stimulus with the specified marker point
     */
    const VisualPreferenceInfo& getVisPrefInfoFromMPConst(MarkerPoint mp) const;
    VisualPreferenceInfo&       getVisPrefInfoFromMP(MarkerPoint mp);

    /**
     * Overridden implementation of method to determine whether the pollinator should
     * harvest the specified flower using its visual perception. This is a special case
     * called by isVisitCandidate() in the case that m_ConstancyType is VISUAL.
     */
    bool isVisitCandidateVisual(Flower* pFlower) const override;

    /**
     * Overridden implementation of method to update the pollinator's visual preference
     * data after each visit to a flower.
     */
    void updateVisualPreferences(const Flower* pFlower, int nectarCollected) override;

private:
    std::vector<VisualPreferenceInfo>       m_VisualPreferences;///< record of the pollinator's current preferences for
                                                                ///< difference visual stimuli

    static std::vector<VisualStimulusInfo>  m_sVisData;         ///< vector containing data relating to pollinator's
                                                                ///< visual sensation of stimuli at different
                                                                ///< marker point values indexed as with m_VisMPDetectionProbs

    static MarkerPoint              m_sVisDataMPMin;	        ///< defines the marker point of the first entry in the
                                                                ///< m_VisData vector

    static MarkerPoint              m_sVisDataMPStep;	        ///< defines the marker point increment between entries in the
                                                                ///< m_VisData vector

    static MarkerPoint              m_sVisDataMPMax;	        ///< defines the marker point of the final entry in the
                                                                ///< m_VisData vector

    static float                    m_sVisBaseProbLandTarget;   ///< the base probability that a pollinator of this species will
                                                                ///< land on a flower that it judges to match its target type

    static float                    m_sVisProbLandNoTargetSetDelta; ///< the delta probability to add to the baseProbLandNonTarget[mp]
                                                                    ///< probability in the case where the pollinator does not yet
                                                                    ///< have any target

    static bool                     m_sbStaticsInitialised;     ///< Flags whether statics have been initialised from config file

    /**
     * String description of the Hymenoptera type, for use in log files
     */
    static std::string m_sTypeNameStr;

    // private helper methods
    static const VisualStimulusInfo& getVisStimInfoFromMP(MarkerPoint mp);
    static std::size_t getVisualDataVectorIdx(MarkerPoint mp);
    static float getBaseProbLandNonTargetInnate(MarkerPoint mp);
};

#endif /* _HYMENOPTERA_H */
