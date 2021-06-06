#pragma once
#include "Twia.h"

namespace Twia
{
    class TwiaManager
    {
    public:

        Status AddTwia(Twia t);
        std::vector<Twia> GetTwias();

        Status SerializeAllTwias();

    private:

        std::vector<Twia> twias;

    };

    inline Status TwiaManager::AddTwia(Twia t)
    {
        twias.push_back(t);

        return Status::OK();
    }

    inline std::vector<Twia> TwiaManager::GetTwias()
    {
        return twias;
    }
}