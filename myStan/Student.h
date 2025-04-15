
#include "User.h"
#include "Course.h"
#include <vector>

class Student : public User {
public:
    Student(int id, string name, string password);
    void menu();
    void registerCourse();
    void submitHomework();
    void viewGrades();
};