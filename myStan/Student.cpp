#include "Student.h"
Student::Student(int id, string name, string password):User(id,name,password) {}

json Student::toJSON() {
    json j = User::toJSON();
    j["role"] = "Student";
    return j;
}