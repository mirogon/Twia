#include "Task.h"

namespace Twia
{
    Task::Task(PRIORITY pPrio, const std::string& pName, const std::string& pDesc, Poco::DateTime pStartTime, Poco::Timespan duration)
    {
        Status s = Initialize(pPrio, pName, pDesc, pStartTime, duration);
        if ( s != STATUS::OK)
        {
            throw std::invalid_argument(s.description);
        }
    }

    Status Task::Initialize(PRIORITY pPrio, const std::string& pName, const std::string& pDesc, Poco::DateTime pStartTime, Poco::Timespan pDuration)
    {
        isInitialized = true;

        name = pName;

        description = pDesc;
        priority = pPrio;

        startTime = pStartTime;
        duration = pDuration;

        return Status::OK("");
    }
    bool Task::HasStarted()
    {
        //Get current time
        Poco::Timestamp now;
        Poco::DateTime nowTime(now);

        if (startTime < nowTime)
        {
            return true;
        }
        return false;
    }
}