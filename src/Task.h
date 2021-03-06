#include "global.h"

namespace Twia
{
    class DateTime : public Poco::DateTime
    {
    public:
        using Poco::DateTime::DateTime;

        std::string ToString()
        {
            std::stringstream ss;
            ss << hour() << ":" << minute() << " " << day() << "/" << month() << "/" << year();
            return ss.str();
        }
        std::string DayString()
        {
            std::stringstream ss;
            ss << day() << "/" << month() << "/" << year();
            return ss.str();
        }
    };

    class LocalDateTime : public Poco::LocalDateTime
    {
    public:

        using Poco::LocalDateTime::LocalDateTime;

        std::string ToString()
        {
            std::stringstream ss;
            ss << hour() << ":" << minute() << " " << day() << "/" << month() << "/" << year();
            return ss.str();
        }
    };

    enum class PRIORITY : uint8_t
    {
        PRIO_1 = 1,
        PRIO_2 = 2,
        PRIO_3 = 3,
        PRIO_4 = 4,
        PRIO_5 = 5,
        PRIO_6 = 6,
        PRIO_7 = 7,
        PRIO_8 = 8,
        PRIO_9 = 9,
        PRIO_10 = 10
    };

    enum class COMPLETED_STATUS : uint8_t
    {
        CS_FAILURE = 0,
        CS_BAD = 1,
        CS_OK = 2,
        CS_GOOD = 3
    };

    enum class SCORE : short
    {
        SCORE_0 = 0,
        SCORE_1 = 1,
        SCORE_2 = 2,
        SCORE_3 = 3,
        SCORE_4 = 4,
        SCORE_5 = 5,
        SCORE_6 = 6,
        SCORE_7 = 7,
        SCORE_8 = 8,
        SCORE_9 = 9
    };

    class Task
    {

    public:

        //Do
        Task() = default;
        Task(PRIORITY pPrio, const std::string& pName, const std::string& pDesc, DateTime startTime, Poco::Timespan duration, bool isSerialized = false);
        ~Task() = default;
        Status Initialize(PRIORITY pPrio, const std::string& pName, const std::string& pDesc, DateTime startTime, Poco::Timespan duration, bool isSerialized = false);
        
        void ExtendTime(Poco::Timespan timeToExtend);
        void Start();
        void Complete(COMPLETED_STATUS status);

        //SET/GET
        bool HasStarted();
        bool IsCompleted();

        M1::M1UID UID();
        std::string Name();
        std::string Description();
        PRIORITY Priority();
        DateTime StartTime();
        LocalDateTime StartTimeLocal();
        Poco::Timespan Duration();
        SCORE CompletedScore();

    private:
        DateTime startTime;
        Poco::Timespan duration;

        std::string name;
        std::string description;

        M1::M1UID uid;
        PRIORITY priority;
        SCORE completedScore;

        uint16_t durationExtended;

        bool isSerialized;
        bool completed;
        bool startedOnTime;
    };
    inline M1::M1UID Task::UID()
    {
        return uid;
    }
    inline std::string Task::Name()
    {
        return name;
    }
    inline std::string Task::Description()
    {
        return description;
    }
    inline PRIORITY Task::Priority()
    {
        return priority;
    }
    inline DateTime Task::StartTime()
    {
        return startTime;
    }
    inline LocalDateTime Task::StartTimeLocal()
    {
        return LocalDateTime(startTime);
    }
    inline Poco::Timespan Task::Duration()
    {
        return duration;
    }
    inline SCORE Task::CompletedScore()
    {
        if(completed)
        {
            return completedScore;
        }
        globalLogger.Log("Task", M1::LOG_ERROR, "Completed score retrieval is invalid");
        return SCORE::SCORE_0;
    }
}   

