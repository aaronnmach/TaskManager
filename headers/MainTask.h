#ifndef MAINTASK_H
#define MAINTASK_H

#include "Task.h"
#include "SubTask.h"
#include <ctime>
#include <vector>

class MainTask : public Task
{
private:
    time_t ddl;
    vector<SubTask *> allSubtasks;
    unsigned int recurringEventTime;
    bool ddlPassed;

public:
    // constructors and destrcutors
    MainTask();
    MainTask(time_t Ddl, unsigned int RecurringEventTime, bool DdlPassed);
    MainTask(time_t Ddl, unsigned int RecurringEventTime, bool DdlPassed, std::string Name, std::string Description, unsigned int Priority);
    ~MainTask();

    // booleans

    bool isRecurring();
    bool isDdlPassed();
    // getters
    time_t getDdl();
    unsigned int getRecurringEventTime();
    vector<SubTask *> getAllSubtasks();
    // achieves something
    int addSubtask(SubTask *);
    void editDdl(time_t newDdl);
    void editRecurringEventTime(unsigned int newRecurringEventTime);
    void editDdlPassed(bool passed);
    int updateDdlPassed();
    int deleteSubtask(int index);
    int sort();
};
#endif