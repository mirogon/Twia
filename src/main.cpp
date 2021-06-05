#include "TaskManager.h"


using namespace Twia;

/*Twia (Time while/whilst im awake)- Twia task list that is stored permanently(xml), tasks have a description, priority, start time, duration | Every twia has a score
* TODO: 
* classes: 
* Task - A task with a priority, name/description, time start, duration 
* TaskManager - Creates tasks, looks for task start/completion, logs task status
*
*/

int main()
{   
    Poco::Timestamp now;
    Duration d(2, 50);
    Task test1;
    test1.Initialize(PRIORITY::PRIO_10, "Wash Bowl", "Wash bowl until it is clean!", Time::FromDateTime(Poco::DateTime(now)), d);

    TaskManager tm;
    tm.AddTask(test1);
    tm.PrintTasks();

    system("pause");
    return 0;
}