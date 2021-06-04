#include "Task.h"

namespace Twia
{
    Task::Task(Priority pPrio, const std::string& pDesc,  Time& startTime, Duration duration)
    {
        Status s = Initialize(pPrio, pDesc, startTime, duration);
        if ( s != STATUS::OK)
        {
            //FAILURE TO INIT
            throw std::invalid_argument(s.description);
        }
    }

    Status Task::Initialize(Priority pPrio, const std::string& pDesc, Time& pStartTime, Duration pDuration)
    {
        isInitialized = true;
        //Check values
        if (!pStartTime.IsValid())
        {
            return Status::FAILURE("Invalid argument start time");
        }

        description = pDesc;
        priority = pPrio;

        startTime = Poco::DateTime(pStartTime.year, pStartTime.month, pStartTime.hour, pStartTime.minute);
        duration = Poco::Timespan(0, pDuration.hours, pDuration.minutes, 0, 0);

        return Status::OK("");
    }
}