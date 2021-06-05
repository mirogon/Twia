#include "global.h"

#include <Poco/DateTime.h>

namespace Twia
{
    enum class PRIORITY
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

    enum class MONTH : uint8_t
    {
        JANUARY = 1,
        FEBRUARY = 2,
        MARCH = 3,
        APRIL = 4,
        MAY = 5,
        JUNE= 6,
        JULY = 7,
        AUGUST = 8,
        SEPTEMBER = 9,
        OCTOBER = 10,
        NOVEMBER = 11,
        DECEMBER = 12
    };

    struct Time
    {
        static Time FromDateTime(const Poco::DateTime& dt)
        {
            Time t;
            t.year = dt.year();
            t.month = dt.month();
            t.day = dt.day();
            t.hour = dt.hour();
            t.minute = dt.minute();
            return t;
        }
        std::string ToString()
        {
            std::stringstream ss;
            ss << (int)hour << ":" << int(minute) << " " << (int)day << "/" << (int)month << "/" << (int)year;
            return ss.str();
        }
        bool IsValid()
        {
            bool valid = true;

            if (!IsInRange(month, 1, 12))
            {
                valid = false;
            }
            if (!IsInRange(day, 1, 31))
            {
                valid = false;
            }
            if (!IsInRange(hour, 1, 23))
            {
                valid = false;
            }
            if (!IsInRange(minute, 1, 59))
            {
                valid = false;
            }

            return valid;
        }
        uint16_t year; //xxxx
        uint8_t month; //xx max 1-12
        uint8_t day; //xx max 1-31
        uint8_t hour; //xx 0-23
        uint8_t minute; //xx max 0-59
    };

    struct Duration
    {
        Duration() = default;
        Duration(uint16_t pHours, uint8_t pMinutes)
        {
            hours = pHours;
            minutes = pMinutes;
        }
        static Duration FromTimespan(const Poco::Timespan& pTimeSpan)
        {
            Duration d;
            d.hours = pTimeSpan.hours();
            d.minutes = pTimeSpan.minutes();
            return d;
        }
        bool IsValid()
        {
            if (IsInRange(minutes, 0, 59) == false)
            {
                return false;
            }
            return true;
        }
        std::string ToString()
        {
            std::stringstream ss;
            ss << int(hours) << "h " << int(minutes) << "m";
            return ss.str();
        }
        
        uint16_t hours; //
        uint8_t minutes; //0-59
    };

    class Task
    {

    public:

        Task() = default;
        Task(PRIORITY pPrio, const std::string& pName, const std::string& pDesc, Time startTime, Duration duration);
        ~Task() = default;

        Status Initialize(PRIORITY pPrio, const std::string& pName,  const std::string& pDesc, Time startTime, Duration duration);
        
        bool HasStarted();

        std::string Name();
        std::string Description();
        PRIORITY Priority();
        Poco::DateTime StartTime();
        Poco::Timespan Duration_();

    private:

        bool isInitialized;

        std::string name;
        std::string description;
        PRIORITY priority;
        Poco::DateTime startTime;
        Poco::Timespan duration;
    };
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
    inline Poco::DateTime Task::StartTime()
    {
        return startTime;
    }
    inline Poco::Timespan Task::Duration_()
    {
        return duration;
    }


}

