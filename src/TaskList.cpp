#include "../headers/TaskList.h"
#include "../headers/MainTask.h"
#include "../headers/helperFunctions.h"
#include "../headers/dfs.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>
#include <algorithm>
#include <pthread.h>
#include <cstdint>

using namespace std;

TaskList::TaskList()
{
}
TaskList::~TaskList()
{
    for (unsigned int i = 0; i < allTasks.size(); i++)
    {
        delete allTasks[i];
    }
}
vector<MainTask *> TaskList::getAllTasks()
{
    return this->allTasks;
}
int TaskList::sort(int userChoice)
{
    if (allTasks.size() == 0)
    {
        return 0;
    }

    if (userChoice == 1) // sort by priority
    {
        for (unsigned int i = 0; i < allTasks.size() - 1; i++)
        {
            allTasks[i]->sort();

            unsigned int minIndex = i;
            for (unsigned int j = i + 1; j < allTasks.size(); j++)
            {
                if (allTasks[j]->getPriority() < allTasks[minIndex]->getPriority())
                {
                    minIndex = j;
                }
            }

            if (minIndex != i)
            {
                MainTask *temp = allTasks[i];
                allTasks[i] = allTasks[minIndex];
                allTasks[minIndex] = temp;
            }
        }
        return 0;
    }
    else if (userChoice == 2)
    { // sort by deadline
        for (unsigned int i = 0; i < allTasks.size() - 1; i++)
        {
            unsigned int minIndex = i;
            for (unsigned int j = i + 1; j < allTasks.size(); j++)
            {
                if (allTasks[j]->getDdl() < allTasks[minIndex]->getDdl())
                {
                    minIndex = j;
                }
            }

            if (minIndex != i)
            {
                MainTask *temp = allTasks[i];
                allTasks[i] = allTasks[minIndex];
                allTasks[minIndex] = temp;
            }
        }
        return 0;
    }
    else
    {
        return -1;
    }
}
int TaskList::addTask()
{

    MainTask *newTask = new MainTask();
    this->allTasks.push_back(newTask);

    return 0;
}

int TaskList::addTask(MainTask *newTask)
{

    this->allTasks.push_back(newTask);

    return 0;
}

int TaskList::deleteTask(int taskIndex)
{
    if (taskIndex < 1 || taskIndex > allTasks.size())
    {
        return -1;
    }

    MainTask *mainTaskToDelete = allTasks[taskIndex - 1];

    delete mainTaskToDelete;
    allTasks.erase(allTasks.begin() + taskIndex - 1);

    return 0;
}

int TaskList::updateDdl()
{
    pthread_t threadID;
    int ret = pthread_create(&threadID, NULL, _updateDdlHelper, this);
    if (ret != 0)
    {
        std::cout << "pthread_create error: error_code=" << ret << std::endl;
        return ret; // Return the error code from pthread_create
    }
    pthread_detach(threadID);
    return ret; // Return the result of pthread_create
}

void *TaskList::_updateDdlHelper(void *arg)
{
    TaskList *parent = static_cast<TaskList *>(arg);
    while (true)
    {
        // get current time
        time_t time_current;
        time(&time_current);
        for (int i = 0; i < parent->allTasks.size(); i++)
        {
            MainTask *mt = parent->allTasks[i];
            // std::cout << "in loop " << i << std::endl;
            if (mt->isRecurring())
            {
                // std::cout << "isRecurring " << i << std::endl;

                if (mt->isDdlPassed()) // already passed, updating it
                {
                    // std::cout << "mt->isDdlPassed()" << i << std::endl;
                    time_t oldDeadLine = mt->getDdl();
                    // std::cout << "ddl before" << oldDeadLine << std::endl;
                    mt->editDdl(_addRecurring(oldDeadLine, mt->getRecurringEventTime()));
                    // std::cout << "ddl after" << mt->getDdl() << std::endl;
                }
                else // not marked passed but it could be.
                {
                    if (mt->getDdl() < time_current) // ddl already passed
                    {
                        // std::cout << " < time_current" << i << std::endl;
                        mt->editDdlPassed(true);
                        time_t oldDeadLine = mt->getDdl();
                        mt->editDdl(_addRecurring(oldDeadLine, mt->getRecurringEventTime()));
                    }
                }
            }
            else // not recurring, do nothing
            {
            }
        } // update all the tasks in list

        sleep(ONE_HOUR);
    }
}
