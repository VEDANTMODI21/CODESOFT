#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Task structure to hold task details
struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

// Function prototypes
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskAsCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks; // Vector to store tasks
    int choice;

    while (true) {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting To-Do List. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

// Function to add a task
void addTask(vector<Task>& tasks) {
    string description;
    cin.ignore(); // Clear input buffer
    cout << "Enter the task description: ";
    getline(cin, description);

    tasks.push_back(Task(description));
    cout << "Task added successfully!\n";
}

// Function to view tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }

    cout << "\n--- Task List ---\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }

    int taskNumber;
    viewTasks(tasks);
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number. Please try again.\n";
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }

    int taskNumber;
    viewTasks(tasks);
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number. Please try again.\n";
    }
}
