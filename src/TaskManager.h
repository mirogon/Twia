#include "Task.h"

namespace Twia
{
    class TaskManager
    {
    public:

        void AddTask(const Task& task);

        std::vector<Task> GetTasks();
        void PrintTasks();

    private:
        std::vector<Task> tasks;
    };


    inline std::vector<Task> TaskManager::GetTasks()
    {
        return tasks;
    }
}
