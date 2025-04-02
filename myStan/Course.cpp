#include "Course.h"
Course::Course(int id, string name, int insid, int capacity) : course_id(id), course_name(name), instructor_id(insid), capacity(capacity) {}

json Course::toJSON()
{
    return json{ {"course_id", course_id},
        {"course_name", course_name},
        {"instructor_id", instructor_id},
        {"capacity", capacity},
        {"students", student_ids},
        {"grades", grades},
        {"announcements", announcements},
        {"homeworks", homeworks}
    };
}

Course Course::fromJSON(const json& j)
{
    Course course(j["course_id"], j["course_name"], j["instructor_id"], j["capacity"]);
    course.student_ids = j["students"].get<vector<int>>();
    course.grades = j["grades"].get<vector<int>>();
    course.announcements = j["announcements"].get<vector<string>>();
    course.homeworks = j["homeworks"].get<vector<string>>();
    return course;
}

json Course::loadCourses()
{
    ifstream file("courses.json");
    if (!file.is_open()) {
        return json::array();
    }
    json courses;
    file >> courses;
    return courses;
}

void Course::saveCourses(const json& courses)
{
    ofstream file("courses.json");
    if (file.is_open()) {
        file << courses.dump(4);
    }
    else {
        cerr << "Error: Unable to open file to save courses!" << endl;
    }
}

void Course::addStudent(int student_id)
{
    if (student_ids.size() >= capacity) {
        cout << "Course is full! Cannot add more students." << endl;
        return;
    }
    student_ids.push_back(student_id);
    grades.push_back(0);
}

void Course::removeStudent(int student_id)
{
    auto it = find(student_ids.begin(), student_ids.end(), student_id);
    if (it != student_ids.end()) {
        size_t index = distance(student_ids.begin(), it);
        student_ids.erase(it);
        grades.erase(grades.begin() + index);
        cout << "Student removed successfully!" << endl;
    }
    else {
        cout << "Student not found in this course!" << endl;
    }
}

void Course::updateDetails(string newName, int newInstructorID, int newCapacity)
{
    course_name = newName;
    instructor_id = newInstructorID;
    capacity = newCapacity;
}

void Course::getStatistics()
{
    cout << "Course Name: " << course_name << endl;
    cout << "Instructor ID: " << instructor_id << endl;
    cout << "Number of Students: " << student_ids.size() << "/" << capacity << endl;
}

void Course::postAnnouncement(string announcement)
{
    announcements.push_back(announcement);
    cout << "Announcement added!" << endl;
}

void Course::addHomework(string homework)
{
    homeworks.push_back(homework);
    cout << "Homework added!" << endl;
}

