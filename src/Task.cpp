#include "../headers/Task.h"
#include "../headers/dfs.h"
#include <ctime>
#include <unistd.h>

#include <iostream>
using namespace std;

Task::Task()
{
    name = "";
    description = "";
    priority = 0;
}

Task::Task(string Name, string Description, unsigned int Priority)
{
    name = Name;
    description = Description;
    priority = Priority;
}

Task::~Task()
{
}

string Task::getName()
{
    return name;
}

string Task::getDescription()
{
    return description;
}

unsigned int Task::getPriority()
{
    return priority;
}

void Task::editName(string newName)
{
    name = newName;
}

void Task::editDescription(string newDescription)
{
    description = newDescription;
}

void Task::editPriority(unsigned int newPriority)
{
    priority = newPriority;
}