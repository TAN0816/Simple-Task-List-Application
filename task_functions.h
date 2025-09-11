#ifndef TASK_FUNCTIONS_H
#define TASK_FUNCTIONS_H

#include <vector>
#include <string>
#include "task.h"
using namespace std;

class TaskFunctions {
private:
    vector<Task> tasks;

public:
    void addTask();
    void viewAllTasks() const;
    void markTaskCompleted();
    void deleteTask();

    bool isValidDate(const std::string& date) const;
};

#endif