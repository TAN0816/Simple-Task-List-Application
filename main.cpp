#include <iostream>
#include "task_functions.h"

using namespace std;

int main(){
    TaskFunctions functions;

    cout << "=== Task List Application ===\n";

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Task\n";
        cout << "2. View All Tasks\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                functions.addTask();
                break;
            case 2:
                functions.viewAllTasks();
                break;
            case 3:
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}