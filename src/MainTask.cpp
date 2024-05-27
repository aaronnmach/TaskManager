#include "../headers/MainTask.h"
#include <ctime>
#include <vector>
#include "../headers/SubTask.h"
#include "../headers/dfs.h"
#include <iostream>

using namespace std;

// contructors and destructors
MainTask::MainTask()
{
    ddl = 0;
    recurringEventTime = 0;
    ddlPassed = false;
}

MainTask::MainTask(time_t Ddl, unsigned int RecurringEventTime, bool DdlPassed)
{
    ddl = Ddl;
    recurringEventTime = RecurringEventTime;
    ddlPassed = DdlPassed;
}
MainTask::MainTask(time_t Ddl, unsigned int RecurringEventTime, bool DdlPassed, string Name, string Description, unsigned int Priority) : Task(Name, Description, Priority)
{
    ddl = Ddl;
    recurringEventTime = RecurringEventTime;
    ddlPassed = DdlPassed;
}
MainTask::~MainTask()
{
    for (int i = 0; i < allSubtasks.size(); i++)
    {
        delete allSubtasks[i];
    }
}

// booleans
bool MainTask::isRecurring()
{
    if (recurringEventTime = 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool MainTask::isDdlPassed()
{
    return ddlPassed;
}

// getters
time_t MainTask::getDdl()
{
    return ddl;
}

unsigned int MainTask::getRecurringEventTime()
{
    return recurringEventTime;
}
vector<SubTask *> MainTask::getAllSubtasks()
{
    return allSubtasks;
}

// achieves something

int MainTask::addSubtask(SubTask *newSubtask)
{
    allSubtasks.push_back(newSubtask);
    return 0;
}

void MainTask::editDdl(time_t newDdl)
{
    ddl = newDdl;
}
void MainTask::editRecurringEventTime(unsigned int newRecurringEventTime)
{
    recurringEventTime = newRecurringEventTime;
}
void MainTask::editDdlPassed(bool newDdlPassed)
{
    ddlPassed = newDdlPassed;
}
int MainTask::updateDdlPassed()
{
    time_t timep;
    time(&timep);
    if (timep > getDdl())
    {
        editDdlPassed(true);
    }
    else
    {
        editDdlPassed(false);
    }

    return 0;
}
int MainTask::deleteSubtask(int index)
{
    if (index < 1 || index > allSubtasks.size())
    {
        return -1;
    }
    delete allSubtasks[index - 1];
    allSubtasks.erase(allSubtasks.begin() + index - 1);
    return 0;
}
int MainTask::sort()
{ // by priority, selection sort
    for (unsigned int i = 0; i < allSubtasks.size() - 1; i++)
    {
        unsigned int minIndex = i;
        for (unsigned int j = i + 1; j < allSubtasks.size(); j++)
        {
            if (allSubtasks[j]->getPriority() < allSubtasks[minIndex]->getPriority())
            {
                minIndex = j;
            }
        }

        SubTask *temp = allSubtasks[minIndex];
        allSubtasks[minIndex] = allSubtasks[i];
        allSubtasks[i] = temp;
    }
    return 0;
}
