#pragma once
#include "User.h"
#include "Course.h"
class Admin :
    public User
{
public:
    Admin(int id, string name,string password);
    json toJSON();
    void createCourse(Course& course);
    void updateCourse(Course& course);
    void deleteCourse(Course& course);
    void viewCourseList();
    void viewStudentGrades();
    void softDeleteUser(User& user);
    void restoreUser(User& user);
};

