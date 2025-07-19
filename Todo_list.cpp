#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Task {
    string description;
    bool completed = false;
};


vector<Task> todoList;

void addTask() {
    string desc;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, desc);
    Task newTask = {desc, false};
    todoList.push_back(newTask);
    cout << "✅ Task added successfully!\n";
}

// Function to view all tasks
void viewTasks() {
    cout << "\n📋 To-Do List:\n";
    if (todoList.empty()) {
        cout << "No tasks added yet.\n";
        return;
    }

    for (size_t i = 0; i < todoList.size(); i++) {
        cout << i + 1 << ". " << todoList[i].description;
        if (todoList[i].completed)
            cout << " ✔ (Completed)";
        else
            cout << " ✅ (Pending)";
        cout << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted() {
    int index;
    viewTasks();
    cout << "\nEnter task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > todoList.size()) {
        cout << "❌ Invalid task number.\n";
        return;
    }

    todoList[index - 1].completed = true;
    cout << "✔ Task marked as completed!\n";
}

// Function to remove a task
void removeTask() {
    int index;
    viewTasks();
    cout << "\nEnter task number to remove: ";
    cin >> index;

    if (index < 1 || index > todoList.size()) {
        cout << "❌ Invalid task number.\n";
        return;
    }

    todoList.erase(todoList.begin() + index - 1);
    cout << "🗑️ Task removed successfully!\n";
}

//The Display menu
void showMenu() {
    cout << "\n🗂️ To-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}

int main() {
    int choice;

    do {
        showMenu();
        cout << "Choose an option (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "👋 Exiting To-Do List Manager. Goodbye!\n";
                break;
            default:
                cout << "❌ Invalid option. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
