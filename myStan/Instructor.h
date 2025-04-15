#include "User.h"
#include "Course.h"
#include <vector>

class Instructor : public User {
public:
    Instructor(int id, string name, string password);
    void menu();
    void createCourse();
    void addHomework();
    void postAnnouncement();
};