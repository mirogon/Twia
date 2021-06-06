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
        doc.save_file("tasks.xml");

        for (auto it = twias.begin(); it != twias.end(); ++it)
        {
            auto xmlTwia = xmlTwias.append_child("Twia");

            pugi::xml_node startDayNode = xmlTwia.append_child("StartDay");
            startDayNode.text().set(it->StartDay().DayString().c_str());

            pugi::xml_node tasksNode = xmlTwia.append_child("Tasks");


            std::vector<Task> tasks = it->Tasks();
            for (auto itTasks = tasks.begin(); itTasks != tasks.end(); ++it)
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


            }
        }

        return Status::OK();
    }
}