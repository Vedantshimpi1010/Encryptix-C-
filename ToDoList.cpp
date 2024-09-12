#include <iostream>
#include <vector>
using namespace std;


struct Task {
    string name;
    bool isCompleted;
};


void addTask(vector<Task> &tasks) {
    Task newTask;
    cout << "Enter the task name: ";
    cin.ignore(); 
    getline(cin, newTask.name);
    newTask.isCompleted = false; 
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}


void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
        return;
    }

    cout << "\nTo-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name;
        if (tasks[i].isCompleted) {
            cout << " [Completed]" << endl;
        } else {
            cout << " [Pending]" << endl;
        }
    }
    cout << endl;
}

void markTaskCompleted(vector<Task> &tasks) {
    int taskNumber;
    viewTasks(tasks);
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void removeTask(vector<Task> &tasks) {
    int taskNumber;
    viewTasks(tasks);
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;
    
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}


int main() {
    vector<Task> tasks;
    int choice;

    do {
        
        cout << "\nTo-Do List Manager:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
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
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
