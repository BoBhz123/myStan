#include "Admin.h"
#include "Course.h"
#include "User.h"
#include <iostream>

int main() {
    int choice;
    cout << "1. Login\n2. Signup\nEnter choice: ";
    cin >> choice;
    if (choice == 1) {
        User temp(0, "hi", "ho");
        temp.login();
        Admin admin(1, "Admin", "1234");
        admin.menu();
    }
    else if (choice == 2) {
        User temp(0, "h", "h");
        temp.signup();
    }
    return 0;
}
