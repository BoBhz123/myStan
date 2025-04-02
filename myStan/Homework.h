#pragma once
#include <string>
#include <map>
#include "Student.h"

class Homework {
private:
    int homeworkID;
    string title;
    string description;
    string dueDate;
    map<Student, int> grades;
public:
    Homework(int id, string title, string description, string dueDate);
    void assignGrade(Student& student, int grade);
    void getGrades();
};
