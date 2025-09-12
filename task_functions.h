#ifndef TASK_FUNCTIONS_H
#define TASK_FUNCTIONS_H
#include <vector>
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
    bool isValidDate(const string& date) const;
    void sortByDueDate();
    void filterByStatus();
    void printTasks(size_t id, const Task &task) const;
    void printHeader() const;
};

#endif