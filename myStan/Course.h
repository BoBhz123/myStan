#pragma once
#include <vector>
#include "Instructor.h"
#include "Student.h"
#include "Homework.h"
class Course
{
private:
    int course_id;
    string course_name;
    int instructor_id;
    int capacity;
    vector<int> student_ids;
    vector<int> grades;
    vector <string>announcements;
    vector <string>homeworks;
public:
    Course(int id, string name, int insid, int capacity);
    json toJSON();
    static Course fromJSON(const json& j);
    static json loadCourses();  // Read courses.json
    static void saveCourses(const json& j);
    void addStudent(int);
    void removeStudent(int);
    void updateDetails(string newName, int newInstructorID, int newCapacity);
    void getStatistics();
    void postAnnouncement(string announcement);
    void addHomework(string homework);
};

