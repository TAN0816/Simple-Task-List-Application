#include "task_functions.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool TaskFunctions::isValidDate(const std::string &date) const
{
    if (date.length() != 10)
        return false;
    if (date[2] != '-' || date[5] != '-')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 2 || i == 5)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    return true;
}

// Add a new task to the list
void TaskFunctions::addTask()
{
    string taskName, dueDate;

    cout << "\n=========== ADD NEW TASK ===========\n";
    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, taskName);

    if (taskName.empty())
    {
        cout << "\nError: Task name cannot be empty!\n";
        return;
    }

    cout << "Enter due date (DD-MM-YYYY): ";
    getline(cin, dueDate);

    if (!isValidDate(dueDate))
    {
        cout << "\nError: Invalid date format! Please use DD-MM-YYYY\n";
        return;
    }

    tasks.emplace_back(taskName, dueDate);
    cout << "\nTask added successfully!\n";
}

void TaskFunctions::viewAllTasks() const
{
    if (tasks.empty())
    {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\n=========== ALL TASKS ===========\n\n";
    cout << left << setw(5) << "ID"
         << setw(20) << "TASK NAME"
         << setw(15) << "DUE DATE"
         << setw(12) << "STATUS" << endl;

    cout << string(55, '-') << endl; 

    for (size_t i = 0; i < tasks.size(); i++)
    {
        cout << left << setw(5) << (i + 1)
             << setw(20) << tasks[i].getTaskName()
             << setw(15) << tasks[i].getDueDate()
             << setw(12) << (tasks[i].isCompleted() ? "Completed" : "Pending")
             << endl;
    }
}
