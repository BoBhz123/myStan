#pragma once
#include "User.h"
#include "Course.h"
#include <vector>

class Admin : public User {
public:
    Admin(int id, string name, string password);
    void menu();
    void listUsers();
    void deleteUser();
    void viewCourses();
    void calculateAverages();
};
