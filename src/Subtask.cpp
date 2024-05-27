
#include "../headers/Subtask.h"

SubTask::SubTask()
{
}
SubTask::SubTask(string Name, string Description, unsigned int Priority) : Task(Name, Description, Priority)
{
}

SubTask::~SubTask()
{
}