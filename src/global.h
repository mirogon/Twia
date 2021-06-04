#pragma once
#include <iostream>
#include <string>
#include <vector>


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
        static Status OK(const std::string& desc)
        {
            static Status s;
            s.status = STATUS::OK;
            s.description = desc;
            return s;
        }

        static Status FAILURE(const std::string& desc)
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
        Status();
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
}