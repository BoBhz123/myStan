#include "Admin.h"
#include <iostream>

Admin::Admin(int id, string name, string password) : User(id, name, password) {}

void Admin::menu() {
    int choice;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. List Users\n2. Delete User\n3. View Courses\n4. View Averages\n5. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: listUsers(); break;
        case 2: deleteUser(); break;
        case 3: viewCourses(); break;
        case 4: calculateAverages(); break;
        }
    } while (choice != 5);
}

void Admin::listUsers() {
    json users = loadUsers();
    for (auto& u : users) {
        cout << "ID: " << u["id"] << ", Name: " << u["name"] << endl;
    }
}

void Admin::deleteUser() {
    int uid;
    cout << "Enter User ID to delete: ";
    cin >> uid;
    json users = loadUsers();
    for (auto& u : users) {
        if (u["id"] == uid) {
            u["deleted"] = true;
            break;
        }
    }
    saveUsers(users);
    cout << "User deleted (soft delete)." << endl;
}

void Admin::viewCourses() {
    json courses = Course::loadCourses();
    for (auto& c : courses) {
        cout << "Course: " << c["course_name"] << ", Instructor: " << c["instructor_id"] << endl;
    }
}

void Admin::calculateAverages() {
    json courses = Course::loadCourses();
    for (auto& c : courses) {
        auto grades = c["grades"].get<vector<int>>();
        if (!grades.empty()) {
            int total = 0;
            for (int g : grades) total += g;
            cout << "Course " << c["course_id"] << ": Avg Grade = " << (float)total / grades.size() << endl;
        }
    }
}