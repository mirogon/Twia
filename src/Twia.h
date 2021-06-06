#include "Task.h"

namespace Twia
{

    

    class Twia
    {
    public:

        void AddTask(const Task& task);

        std::vector<Task> GetTasks();
        void PrintTasks();

    private:
        DateTime startDay;
        std::vector<Task> tasks;
        SCORE twiaScore;
    };


    inline std::vector<Task> Twia::GetTasks()
    {
        return tasks;
    }
}
