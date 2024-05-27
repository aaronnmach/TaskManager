#ifndef SUBTASK_H
#define SUBTASK_H
#include <string>
#include "Task.h"

class SubTask : public Task
{

private:
public:
    SubTask();
    SubTask(string Name, string Description, unsigned int Priority);
    ~SubTask();
};

#endif