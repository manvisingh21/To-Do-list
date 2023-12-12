#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Task {
    string description;
    bool completed;
    string dueDate;
    string category;
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(string description, string dueDate, string category) {
        Task newTask = {description, false, dueDate, category};
        tasks.push_back(newTask);
        cout << "Task added successfully!\n";
    }

    void markTaskComplete(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as complete!\n";
        } else {
            cout << "Invalid task index!\n";
        }
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            cout << "Task removed successfully!\n";
        } else {
            cout << "Invalid task index!\n";
        }
    }

    void displayTasks() {
        cout << "-------------------------------------------------------------------------\n";
        cout << "      Todo List\n";
        cout << "-------------------------------------------------------------------------\n";

        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << "[" << setw(2) << i + 1 << "] ";
            cout << (tasks[i].completed ? "[X] " : "[ ] ");
            cout << "Due: " << tasks[i].dueDate << " | ";
            cout << "Category: " << tasks[i].category << " | ";
            cout << tasks[i].description << "\n";
        }

        cout << "-------------------------------------------------------------------------\n";
    }
};

int main() {
    TodoList todoList;
    int choice;

    do {
        cout << "Todo List Application\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Complete\n";
        cout << "3. Remove Task\n";
        cout << "4. Display Tasks\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string description, dueDate, category;
                    cout << "Enter task description: ";
                    cin.ignore();
                    getline(cin, description);
                    cout << "Enter due date (e.g., MM/DD/YYYY): ";
                    cin >> dueDate;
                    cout << "Enter task category: ";
                    cin.ignore();
                    getline(cin, category);
                    todoList.addTask(description, dueDate, category);
                }
                break;
            case 2:
                {
                    int index;
                    cout << "Enter the task index to mark as complete: ";
                    cin >> index;
                    todoList.markTaskComplete(index - 1);  // Adjust for 0-based indexing
                }
                break;
            case 3:
                {
                    int index;
                    cout << "Enter the task index to remove: ";
                    cin >> index;
                    todoList.removeTask(index - 1);  // Adjust for 0-based indexing
                }
                break;
            case 4:
                todoList.displayTasks();
                break;
            case 0:
                cout << "Exiting the Todo List Application. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 0);

    return 0;
}
