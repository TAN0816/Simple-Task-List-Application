#include "task.h"

string Task::getTaskName() const {
    return taskName;
}

string Task::getDueDate() const {
    return dueDate;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::markCompleted() {
    completed = true;
}

void Task::setTaskName(const string& name) {
    taskName = name;
}

void Task::setDueDate(const string& date) {
    dueDate = date;
}
