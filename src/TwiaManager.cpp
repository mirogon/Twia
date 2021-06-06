#include "TwiaManager.h"

namespace Twia
{
    Status TwiaManager::SerializeAllTwias()
    {
        //Check if tasks.xml exists and create if not

        if (!std::filesystem::exists("tasks.xml"))
        {
            std::ofstream newFile("tasks.xml", std::ios::out);
            if (newFile.is_open())
            {
                newFile.close();
            }
        }

        pugi::xml_document doc;
        pugi::xml_parse_result r = doc.load_file("tasks.xml");
        
        pugi::xml_node xmlTwias = doc.child("Twias");
        if (xmlTwias.type() == pugi::node_null)
        {
            doc.append_child("Twias");
        }
        

        for (auto it = twias.begin(); it != twias.end(); ++it)
        {
            auto xmlTwia = xmlTwias.append_child("Twia");

            pugi::xml_node startDayNode = xmlTwia.append_child("StartDay");
            startDayNode.text().set(it->StartDay().DayString().c_str());

            pugi::xml_node tasksNode = xmlTwia.append_child("Tasks");


            std::vector<Task> tasks = it->Tasks();
            for (auto itTasks = tasks.begin(); itTasks != tasks.end(); ++itTasks)
            {
                pugi::xml_node taskNode = tasksNode.append_child("Task");

                pugi::xml_node uidNode = taskNode.append_child("UID");
                uidNode.text().set(itTasks->UID().ToString().c_str());

                pugi::xml_node startTimeNode = taskNode.append_child("StartTime");
                pugi::xml_node startTimeDayNode = startTimeNode.append_child("Day");
                startTimeDayNode.text().set(itTasks->StartTime().DayString().c_str());
                pugi::xml_node startTimeHourNode = startTimeNode.append_child("Hour");
                startTimeHourNode.text().set(itTasks->StartTime().hour());
                pugi::xml_node startTimeMinuteNode = startTimeNode.append_child("Minute");
                startTimeMinuteNode.text().set(itTasks->StartTime().minute());

                pugi::xml_node durationNode = taskNode.append_child("Duration");
                durationNode.text().set(itTasks->Duration().totalMinutes());

                pugi::xml_node priorityNode = taskNode.append_child("Priority");
                priorityNode.text().set((int)itTasks->Priority());

                pugi::xml_node nameNode = taskNode.append_child("Name");
                nameNode.text().set(itTasks->Name().c_str());

                pugi::xml_node descNode = taskNode.append_child("Description");
                descNode.text().set(itTasks->Description().c_str());

                int completed;
                pugi::xml_node completedScoreNode = taskNode.append_child("CompletedScore");
                if (itTasks->IsCompleted())
                {
                    completed = (int)itTasks->CompletedScore();
                }
                else
                {
                    completed = -1;
                }
                completedScoreNode.text().set(completed);

            }
        }
        doc.save_file("tasks.xml");
        return Status::OK();
    }
}