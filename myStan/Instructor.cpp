#include "Instructor.h"
#include <iostream>

Instructor::Instructor(int id, string name, string password) : User(id, name, password) {}

void Instructor::menu() {
    int choice;
    do {
        cout << "\n--- Instructor Menu ---\n";
        cout << "1. Create Course\n2. Post Homework\n3. Post Announcement\n4. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: createCourse(); break;
        case 2: addHomework(); break;
        case 3: postAnnouncement(); break;
        }
    } while (choice != 4);
}

void Instructor::createCourse() {
    int cid, cap;
    string cname;
    cout << "Enter Course ID: "; cin >> cid;
    cout << "Enter Course Name: "; cin >> cname;
    cout << "Enter Capacity: "; cin >> cap;
    Course c(cid, cname, this->id, cap);
    json all = Course::loadCourses();
    all.push_back(c.toJSON());
    Course::saveCourses(all);
    cout << "Course created." << endl;
}

void Instructor::addHomework() {
    int cid;
    string hw;
    cout << "Course ID: "; cin >> cid;
    cout << "Homework Description: "; cin.ignore(); getline(cin, hw);
    json all = Course::loadCourses();
    for (auto& c : all) {
        if (c["course_id"] == cid && c["instructor_id"] == id) {
            c["homeworks"].push_back(hw);
            break;
        }
    }
    Course::saveCourses(all);
    cout << "Homework posted." << endl;
}

void Instructor::postAnnouncement() {
    int cid;
    string msg;
    cout << "Course ID: "; cin >> cid;
    cout << "Announcement: "; cin.ignore(); getline(cin, msg);
    json all = Course::loadCourses();
    for (auto& c : all) {
        if (c["course_id"] == cid && c["instructor_id"] == id) {
            c["announcements"].push_back(msg);
            break;
        }
    }
    Course::saveCourses(all);
    cout << "Announcement posted." << endl;
}