#include "Student.h"
#include <iostream>

Student::Student(int id, string name, string password) : User(id, name, password) {}

void Student::menu() {
    int choice;
    do {
        cout << "\n--- Student Menu ---\n";
        cout << "1. Register Course\n2. Submit Homework\n3. View Grades\n4. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: registerCourse(); break;
        case 2: submitHomework(); break;
        case 3: viewGrades(); break;
        }
    } while (choice != 4);
}

void Student::registerCourse() {
    int cid;
    cout << "Enter Course ID to register: "; cin >> cid;
    json all = Course::loadCourses();
    for (auto& c : all) {
        if (c["course_id"] == cid) {
            auto& students = c["students"];
            if (find(students.begin(), students.end(), id) == students.end()) {
                students.push_back(id);
                c["grades"].push_back(0);
                cout << "Registered successfully." << endl;
            }
            else {
                cout << "Already registered." << endl;
            }
            break;
        }
    }
    Course::saveCourses(all);
}

void Student::submitHomework() {
    int cid;
    string ans;
    cout << "Course ID: "; cin >> cid;
    cout << "Submit Answer: "; cin.ignore(); getline(cin, ans);
    cout << "Submission recorded (simulation)." << endl;
}

void Student::viewGrades() {
    json all = Course::loadCourses();
    for (auto& c : all) {
        auto& students = c["students"];
        auto it = find(students.begin(), students.end(), id);
        if (it != students.end()) {
            int idx = distance(students.begin(), it);
            int grade = c["grades"][idx];
            cout << "Course " << c["course_id"] << ": Grade = " << grade << endl;
        }
    }
}
