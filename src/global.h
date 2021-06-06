#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>

#include <Poco/DateTime.h>
#include <Poco/LocalDateTime.h>

#include "pugixml.hpp"

#include <M1Random.h>
#include <M1UID.h>

namespace Twia
{
    enum class STATUS : uint8_t
    {
        UNDEFINED = 0,
        OK = 1,
        FAILURE = 2
    };
    
    struct Status
    {
        static Status OK(const std::string& desc ="")
        {
            static Status s;
            s.status = STATUS::OK;
            s.description = desc;
            return s;
        }

        static Status FAILURE(const std::string& desc ="")
        {
            static Status s;
            s.status = STATUS::FAILURE;
            s.description = desc;
            return s;
        }

        bool operator==(STATUS s)
        {
            if (s == status)
            {
                return true;
            }
            return false;
        }

        bool operator!=(STATUS s)
        {
            if (s != status)
            {
                return true;
            }
            return false;
        }

        std::string description;

    private:
        Status() = default;
        STATUS status;
    };
    
    template <class T>
    bool IsInRange(T value, uint64_t min, uint64_t max)
    {
        if (value > max || value < min)
        {
            return false;
        }
        return true;
    }
    /*
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
    */
}