#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
using namespace std;

class Task
{
private:
    string taskName;
    string dueDate;
    bool completed;

public:
    Task(string name, string date) : taskName(name), dueDate(date), completed(false) {}

    string getTaskName() const;
    string getDueDate() const;
    bool isCompleted() const;
    void markCompleted();
    void setTaskName(const string& name);
    void setDueDate(const string& date);
};

#endif