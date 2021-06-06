#include "Twia.h"

namespace Twia
{
    void Twia::AddTask(const Task& t)
    {
        tasks.push_back(t);
    }

    void Twia::PrintTasks()
    {
        for (auto it = tasks.begin(); it != tasks.end(); ++it)
        {
            std::cout << it->Name() << " " << it->Description() << " StartTime: " << it->StartTimeLocal().ToString() <<" Duration: "<<it->Duration().hours()<<":"<<it->Duration().minutes() << std::endl;
        }
    }
}