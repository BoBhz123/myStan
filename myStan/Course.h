#pragma once
#include <vector>
#include "Instructor.h"
#include "Student.h"
#include "Homework.h"
class Course
{
private:
    int courseID;
    string title;
    int capacity;
    Instructor instructor;
    vector<Student> students;
    vector<string> announcements;
    vector<Homework> homeworks;
public:
    Course(int id, string title, Instructor instructor, int capacity);
    void addStudent(Student& student);
    void removeStudent(Student& student);
    void updateDetails();
    void getStatistics();
    void postAnnouncement(string announcement);
    void addHomework(Homework& homework);
};

