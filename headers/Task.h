#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

class Task
{
private:
    string name;
    string description;
    unsigned int priority;

public:
    Task();
    Task(string Name, string Description, unsigned int Priority);
    ~Task();
    string getName();
    string getDescription();
    unsigned int getPriority();
    void editName(string newName);
    void editDescription(string newDescription);
    void editPriority(unsigned int newPriority);
};

#endif