#pragma once
#include "User.h"
#include "Course.h"
class Student :
    public User
{public:
    Student(int id, string name,string password);
    json toJSON() ;

    void enrollCourse(Course& course);
    void dropCourse(Course& course);
    void viewGrades();
    void viewCourses();
    void rateInstructor(Instructor& instructor, int rating);
};

