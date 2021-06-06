#include "Task.h"

namespace Twia
{
    Task::Task(PRIORITY pPrio, const std::string& pName, const std::string& pDesc, DateTime pStartTime, Poco::Timespan pDuration, bool pIsSerialized)
    {
        Status s = Initialize(pPrio, pName, pDesc, pStartTime, pDuration, pIsSerialized);
        if ( s != STATUS::OK)
        {
            throw std::invalid_argument(s.description);
        }
    }

    Status Task::Initialize(PRIORITY pPrio, const std::string& pName, const std::string& pDesc, DateTime pStartTime, Poco::Timespan pDuration, bool pIsSerialized)
    {
        isSerialized = pIsSerialized;
        name = pName;
        completed = false;
        completedScore = SCORE::SCORE_1;
        durationExtended = 0;
        startedOnTime = false;

        description = pDesc;
        priority = pPrio;

        startTime = pStartTime;
        duration = pDuration;

        return Status::OK("");
    }
    void Task::ExtendTime(Poco::Timespan timeToExtend)
    {
        static bool firstTime = true;
        static Poco::Timespan originalDuration;
        if (firstTime)
        {
            originalDuration = duration;
            firstTime = false;
        }

        durationExtended += (timeToExtend.minutes() / duration.minutes() * 100);
        duration += timeToExtend;
    }
    void Task::Start()
    {
        startedOnTime = true;

        Poco::Timestamp now;
        Poco::DateTime nowTime(now);

        if ( nowTime > (startTime + Poco::Timespan(300, 0)) );
        {
            startedOnTime = false;
        }
    }
    void Task::Complete(COMPLETED_STATUS pStatus)
    {
        int calculatedCompletedScore = (int)SCORE::SCORE_1;
        completed = true;

        switch (pStatus)
        {
        case COMPLETED_STATUS::CS_FAILURE: calculatedCompletedScore = (int)SCORE::SCORE_1; break;
        case COMPLETED_STATUS::CS_BAD: calculatedCompletedScore = (int)SCORE::SCORE_3; break;
        case COMPLETED_STATUS::CS_OK: calculatedCompletedScore = (int)SCORE::SCORE_6; break;
        case COMPLETED_STATUS::CS_GOOD: calculatedCompletedScore = (int)SCORE::SCORE_9; break;
        }

        if (!startedOnTime)
        {
            calculatedCompletedScore -= 1;
        }

        int durationExtendedPunishment = durationExtended / 25;
        if (durationExtendedPunishment > 3)
        {
            durationExtendedPunishment = 3;
        }
        calculatedCompletedScore -= durationExtendedPunishment;

        if (calculatedCompletedScore < (int)SCORE::SCORE_0)
        {
            calculatedCompletedScore = (int)SCORE::SCORE_0;
        }

        completedScore = (SCORE)calculatedCompletedScore;
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
    bool Task::IsCompleted()
    {
        return completed;
    }
}