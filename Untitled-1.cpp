#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(std::string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& taskDescription) {
        tasks.emplace_back(taskDescription);
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed) {
                std::cout << " [Completed]";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;
    std::string description;
    int taskIndex;

    do {
        std::cout << "\nTo-Do List Application\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Completed\n";
        std::cout << "3. View Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // To ignore the newline character after the integer input

        switch (choice) {
        case 1:
            std::cout << "Enter task description: ";
            std::getline(std::cin, description);
            todoList.addTask(description);
            break;
        case 2:
            std::cout << "Enter task number to mark as completed: ";
            std::cin >> taskIndex;
            todoList.markTaskCompleted(taskIndex - 1);
            break;
        case 3:
            todoList.viewTasks();
            break;
        case 4:
            std::cout << "Exiting the application.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
