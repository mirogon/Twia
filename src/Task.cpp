#include "Task.h"

namespace Twia
{
    Task::Task(PRIORITY pPrio, const std::string& pName, const std::string& pDesc, Time startTime, Duration duration)
    {
        Status s = Initialize(pPrio, pName, pDesc, startTime, duration);
        if ( s != STATUS::OK)
        {
            throw std::invalid_argument(s.description);
        }
    }

    Status Task::Initialize(PRIORITY pPrio, const std::string& pName, const std::string& pDesc, Time pStartTime, Duration pDuration)
    {
        isInitialized = true;
        //Check values
        if (!pStartTime.IsValid())
        {
            return Status::FAILURE("Invalid argument start time");
        }

        name = pName;

        description = pDesc;
        priority = pPrio;

        startTime = Poco::DateTime(pStartTime.year, pStartTime.month, pStartTime.day, pStartTime.hour, pStartTime.minute);
        duration = pDuration;

        return Status::OK("");
    }
    bool Task::HasStarted()
    {
        //Get current time
        Poco::Timestamp now;
        Time nowTime = Time::FromDateTime(Poco::DateTime(now));

        Poco::DateTime t(now);
        t.

    }
}