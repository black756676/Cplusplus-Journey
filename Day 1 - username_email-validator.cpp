#include <iostream>
#include <string>
using namespace std;

int main() {
    string username;
    string email;

    cout << "Enter username: ";
    getline(cin, username);

    cout << "Enter email: ";
    getline(cin, email);

    if (username.empty()) {
        cout << "Username cannot be empty";
    } else if (username.length() < 5) {
        cout << "Username must be at least 5 characters";
    } else if (email.find("@") == string::npos) {
        cout << "Invalid email, @ missing";
    } else if (email.find(".") == string::npos) {
        cout << "Invalid email, dot missing";
    } else {
        cout << "Account created successfully";
    }

    return 0;
}
