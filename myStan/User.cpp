#include "User.h"

json User::toJSON()
{
    return json{ {"id", id}, {"name", name},{"password",password} };
}

User User::fromJSON(const json& j)
{
    return User(j["id"], j["name"],j["password"]);
}

json User::loadUsers()
{
    ifstream file("users.json");
    if (!file.is_open()) {
        return json::array();

    }
    json users;
    file >> users;
    return users;
}

void User::saveUsers(const json& users)
{
 
    ofstream file("users.json");
    if (file.is_open()) {
        file << users.dump(4);
    }

 else {
     cerr << "Error: Unable to open the file to save users!" << endl;
        }
}

User::User(int id, string name, string password) :id(id), name(name), password(password)
{}
void User::signup() {
    json users = loadUsers();
    string Name, Password;
    int ID;

    while (true) {
        cout << "Enter ID: ";
        cin >> ID;
        if (userExist(ID)) {
            cout << "User already exists. Try again." << endl;
        }
        else {
            cout << "Enter Password: ";
            cin >> Password;
            cout << "Enter Name: ";
            cin >> Name;
            break; 
        }
    }

    
    User newUser(ID, Name, Password);
    users.push_back(newUser.toJSON());
    saveUsers(users);

    cout << "Sign-up Successful!" << endl;
}
void User::login()
{
    json users = loadUsers();
    string Password;
    int ID;
    bool loggedIn = false; 

    while (!loggedIn) {
        cout << "Enter an ID number: ";
        cin >> ID;
        cout << "Enter a password: ";
        cin >> Password;

        for (size_t i = 0; i < users.size(); i++)
        {
            if (users[i]["id"] == ID && users[i]["password"] == Password) {
                cout << "Login successful! Welcome, " << users[i]["name"] << "!" << endl;
                loggedIn = true; 
                return; 
            }
        }
        cout << "Invalid ID or password. Please try again.\n";
    }
}

void User::logout()
{
}

bool User::userExist(int id)
{
    json users = loadUsers();
    for (int i = 0; i <users.size(); i++)
    {
        if (users[i]["id"] == id) {
            return true;
        }
    }
    return false;
}
