#include <string>
#include <nlohmann/json.hpp>
#include <iostream>
using namespace std;
using json = nlohmann::json;

class User {
public:
    int id;
    string name;
    string password;

    User(int id, const string name,const string password);
    json toJSON();
    static User fromJSON(const json& j);
    static json loadUsers();
    static void saveUsers(const json& users);
    void signup();
    void login();
    void logout();
    bool userExist(int id);
};
