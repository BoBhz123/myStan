#include "Instructor.h"

Instructor::Instructor(int id, string name, string password):User(id,name,password)
{
}

json Instructor::toJSON()
{
    json j = User::toJSON();
    j["role"] = "Instructor";
    return j;
}
