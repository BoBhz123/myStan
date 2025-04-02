#include "Admin.h"

Admin::Admin(int id, string name,string password):User(id,name,password)
{
}

json Admin::toJSON() 
{
    json j = User::toJSON();
    j["role"] = "Admin";
    return j;
}
