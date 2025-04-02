#pragma once
#include <iostream> 
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;
class User {
protected:
    int id;
    string name;
    string password;
public:
    json toJSON();
    static User fromJSON(const json& j);
    static json loadUsers();  // Read users.json
    static void saveUsers(const json& j); // Write to users.json
    User(int id, string name,string password);
    virtual void signup();
    virtual void login();
    virtual void logout();
    bool userExist(int id);
};


