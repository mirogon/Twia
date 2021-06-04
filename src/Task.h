#include "global.h"

#include <Poco/DateTime.h>

namespace Twia
{
    enum class Priority
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

    enum class Month : uint8_t
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
        uint16_t hours; //xx 1-23
        uint8_t minutes; //xx 1-59
    };

    class Task
    {

    public:

        Task() = default;
        Task(Priority pPrio, const std::string& pDesc, Time& startTime, Duration duration);
        ~Task() = default;

        Status Initialize(Priority pPrio, const std::string& pDesc, Time& startTime, Duration duration);

    private:

        bool isInitialized;

        std::string description;
        Priority priority;
        Poco::DateTime startTime;
        Poco::Timespan duration;
    };
}
