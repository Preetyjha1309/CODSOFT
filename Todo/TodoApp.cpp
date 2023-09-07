#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Initialize a vector to store tasks
vector<string> tasks;

// Function to display the current tasks
void displayTasks() {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

// Function to add a task
void addTask(const string& task) {
    tasks.push_back(task);
    cout << "Task '" << task << "' added." << endl;
}

// Function to delete a task by its index
void deleteTask(int index) {
    if (index >= 1 && index <= tasks.size()) {
        cout << "Task '" << tasks[index - 1] << "' deleted." << endl;
        tasks.erase(tasks.begin() + index - 1);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    while (true) {
        cout << "\nOptions:" << endl;
        cout << "1. View tasks" << endl;
        cout << "2. Add a task" << endl;
        cout << "3. Delete a task" << endl;
        cout << "4. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayTasks();
                break;
            case 2:
                {
                    cin.ignore(); // Clear the input buffer
                    string task;
                    cout << "Enter the task: ";
                    getline(cin, task);
                    addTask(task);
                }
                break;
            case 3:
                displayTasks();
                int index;
                cout << "Enter the task number to delete: ";
                cin >> index;
                deleteTask(index);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
