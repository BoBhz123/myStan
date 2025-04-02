#pragma once
#include "User.h"
class Student :
    public User
{public:
    Student(int id, string name, string email);
    void enrollCourse(Course& course);
    void dropCourse(Course& course);
    void viewGrades();
    void viewCourses();
    void rateInstructor(Instructor& instructor, int rating);
};

