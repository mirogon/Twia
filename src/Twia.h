#include "Task.h"

namespace Twia
{
    class Twia
    {
    public:

        void AddTask(const Task& task);
        void PrintTasks();

        std::vector<Task> Tasks();
        DateTime StartDay();

    private:
        DateTime startDay;
        std::vector<Task> tasks;
        SCORE twiaScore;
    };

    
    inline std::vector<Task> Twia::Tasks()
    {
        return tasks;
    }
    inline DateTime Twia::StartDay()
    {
        return startDay;
    }
}
