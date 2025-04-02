#pragma once
#include <iostream> 
#include <string>
using namespace std;
class User {
protected:
    int id;
    string name;
    string email;
public:
    User(int id, string name, string email);
    virtual void login();
    virtual void logout();
};

