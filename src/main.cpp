#include "TwiaManager.h"

//using namespace Twia;

/*Twia (Time while/whilst im awake)- Twia task list that is stored permanently(xml), tasks have a description, priority, start time, duration | Every twia has a score
* TODO: 
* classes: 
* Task - A task with a priority, name/description, time start, duration 
* TaskManager - Creates tasks, looks for task start/completion, logs task status
*
*/

int main()
{   

    Twia::globalLogger.SetConsoleLogging(true);
    Twia::globalLogger.SetFileLogging(true, "error.log", M1::LogType::LOG_WARNING);

    Poco::Timestamp now;
    Twia::Task test1;
    test1.Initialize(Twia::PRIORITY::PRIO_10, "Wash Bowl", "Wash bowl until it is clean!", Twia::DateTime(now), Poco::Timespan(3600, 0));
    
    Twia::Twia tm;
    tm.AddTask(test1);
    
    Twia::TwiaManager twiaManager;
    twiaManager.AddTwia(tm);

    twiaManager.SerializeAllTwias();

    system("pause");
    return 0;
}