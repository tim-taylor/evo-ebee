/**
 * @file
 *
 * Declaration of the EvoBeeExperiment class
 */

#ifndef _EVOBEEEXPERIMENT_H
#define _EVOBEEEXPERIMENT_H

#include <thread>
#include "EvoBeeModel.h"
#include "EventManager.h"
#include "Logger.h"
#include "Visualiser.h"


/**
 * Definition of allowable generation termination types
 */
enum class GenTerminationType {
    NUM_SIM_STEPS,          ///< number of simulation steps (takes int param)
    NUM_POLLINATOR_STEPS,   ///< total number of steps taken by all pollinators (takes int param)
    POLLINATED_FRACTION     ///< a given fraction of all plants have been pollinated (takes float param)
};


/**
 * The EvoBeeExperiment class ...
 */
class EvoBeeExperiment {

public:
    EvoBeeExperiment();
    ~EvoBeeExperiment();

    void run();

    EvoBeeModel     m_Model;
    EventManager    m_EventManager;
    Logger          m_Logger;
    Visualiser      m_Visualiser;

private:
    bool            m_bVis;
    int             m_iVisUpdatePeriod;
    int             m_iLogUpdatePeriod;
    std::thread     m_threadLog;
};

#endif /* _EVOBEEEXPERIMENT_H */
