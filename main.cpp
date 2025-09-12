#include <iostream>
#include "task_functions.h"

using namespace std;

void menu()
{
    cout << "\n===== MENU =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View All Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Sort Tasks by Due Date" << endl;
    cout << "6. Filter Tasks by Status" << endl;
    cout << "7. Exit" << endl;
    cout << "Choose option: ";
}

void menuOption(int option, TaskFunctions &functions)
{
    switch (option)
    {
    case 1:
        functions.addTask();
        break;
    case 2:
        functions.viewAllTasks();
        break;
    case 3:
        functions.markTaskCompleted();
        break;
    case 4:
        functions.deleteTask();
        break;
    case 5:
        functions.sortByDueDate();
        break;
    case 6:
        functions.filterByStatus();
        break;
    case 7:
        cout << "Bye! Thanks for using the Task List Application :)" << endl;
        break;
    default:
        cout << "Please choose a valid option (1-7)!\n";
    }
}

int main()
{
    TaskFunctions functions;
    int option;

    cout << "=== Simple Task List Application ===\n";

    do
    {
        menu();
        cin >> option;
        menuOption(option, functions);
    } while (option != 7);

    return 0;
}