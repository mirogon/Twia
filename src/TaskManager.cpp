#include "TaskManager.h"

namespace Twia
{
    void TaskManager::AddTask(const Task& t)
    {
        tasks.push_back(t);
    }

    void TaskManager::PrintTasks()
    {
        for (auto it = tasks.begin(); it != tasks.end(); ++it)
        {
            std::cout << it->Name() << " " << it->Description() << " StartTime: " << it->StartTime().ToString() <<" Duration: "<<it->Duration_().ToString() << std::endl;
        }
    }
}