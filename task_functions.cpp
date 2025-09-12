#include "task_functions.h"
#include <iostream>
#include <iomanip>
#include <string>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"

using namespace std;

bool TaskFunctions::isValidDate(const string &date) const
{
    if (date.length() != 10)
        return false;
    if (date[2] != '/' || date[5] != '/')
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

void TaskFunctions::printTasks(size_t id, const Task &task) const
{
    string color = task.isCompleted() ? GREEN : RED;

    cout << color
         << left << setw(5) << id
         << setw(20) << task.getTaskName()
         << setw(15) << task.getDueDate()
         << setw(12) << (task.isCompleted() ? "Completed" : "Pending")
         << RESET << endl;
}

void TaskFunctions::printHeader() const
{
    cout << left << setw(5) << "ID"
         << setw(20) << "TASK NAME"
         << setw(15) << "DUE DATE"
         << setw(12) << "STATUS" << endl;
    cout << string(55, '-') << endl;
}

// Add new task 
void TaskFunctions::addTask()
{
    string taskName, dueDate;

    cout << "\n=========== ADD NEW TASK ===========\n";
    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, taskName);

    if (taskName.empty())
    {
        cout << "\nTask name cannot be empty!\n";
        return;
    }

    cout << "Enter due date (DD/MM/YYYY): ";
    getline(cin, dueDate);

    if (!isValidDate(dueDate))
    {
        cout << "\nInvalid date format! Please use DD/MM/YYYY\n";
        return;
    }

    tasks.emplace_back(taskName, dueDate);
    cout << "\nTask added successfully!\n";
}

//View all tasks
void TaskFunctions::viewAllTasks() const
{
    if (tasks.empty())
    {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\n================== ALL TASKS ================\n\n";
    printHeader();

    for (size_t i = 0; i < tasks.size(); i++)
    {
        printTasks(i + 1, tasks[i]);
    }
}

// Update task status
void TaskFunctions::markTaskCompleted()
{
    if (tasks.empty())
    {
        cout << "\nNo tasks available to mark.\n";
        return;
    }
    viewAllTasks();

    int id;
    cout << "\nEnter the task ID to mark as completed: ";
    cin >> id;

    // Validate input
    if (id < 1 || id > (int)tasks.size())
    {
        cout << "\nInvalid task ID!\n";
        return;
    }

    if (tasks[id - 1].isCompleted())
    {
        cout << "\nTask is already completed!\n";
    }
    else
    {
        tasks[id - 1].markCompleted();
        cout << "\nTask \"" << tasks[id - 1].getTaskName() << "\" marked as completed!\n";
    }
}

// delete task
void TaskFunctions::deleteTask()
{
     if (tasks.empty())
    {
        cout << "\nNo tasks available to delete.\n";
        return;
    }

    viewAllTasks();

    int id;
    cout << "\nEnter the task ID to delete: ";
    cin >> id;

    if (id < 1 || id > (int)tasks.size())
    {
        cout << "\nInvalid task ID!\n";
        return;
    }

    tasks.erase(tasks.begin() + id - 1);
    cout << "\nTask deleted successfully!\n";
}

void TaskFunctions::sortByDueDate() {}
void TaskFunctions::filterByStatus(){}
