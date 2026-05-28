#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    string name;
    string email;
    float marks;
};

bool compareMarks(Student a, Student b) {
    return a.marks > b.marks;
}

int main() {
    vector<Student> students;
    int choice;

    srand(time(0));

    do {
        cout << endl;
        cout << "===== Student Manager =====" << endl;
        cout << "1. Add student" << endl;
        cout << "2. View students" << endl;
        cout << "3. Sort by marks" << endl;
        cout << "4. Delete student" << endl;
        cout << "5. Save to file" << endl;
        cout << "6. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Student temp;

            temp.id = rand() % 9000 + 1000;

            cout << "Enter name: ";
            getline(cin, temp.name);

            if (temp.name.empty()) {
                cout << "Name cannot be empty" << endl;
                continue;
            }

            if (temp.name.length() < 3) {
                cout << "Name is too short" << endl;
                continue;
            }

            cout << "Enter email: ";
            getline(cin, temp.email);

            if (temp.email.find("@") == string::npos) {
                cout << "Invalid email, @ missing" << endl;
                continue;
            }

            cout << "Enter marks: ";
            cin >> temp.marks;
            cin.ignore();

            students.push_back(temp);

            cout << "Student added successfully" << endl;

        } else if (choice == 2) {
            if (students.size() == 0) {
                cout << "No students found" << endl;
            } else {
                cout << endl;
                cout << "===== All Students =====" << endl;

                for (int i = 0; i < students.size(); i++) {
                    cout << "ID: " << students[i].id << endl;
                    cout << "Name: " << students[i].name << endl;
                    cout << "Email: " << students[i].email << endl;
                    cout << "Marks: " << students[i].marks << endl;
                    cout << endl;
                }
            }

        } else if (choice == 3) {
            sort(students.begin(), students.end(), compareMarks);
            cout << "Students sorted by marks" << endl;

        } else if (choice == 4) {
            int id;
            bool found = false;

            cout << "Enter student ID to delete: ";
            cin >> id;
            cin.ignore();

            for (int i = 0; i < students.size(); i++) {
                if (students[i].id == id) {
                    students.erase(students.begin() + i);
                    found = true;
                    cout << "Student deleted" << endl;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found" << endl;
            }

        } else if (choice == 5) {
            ofstream file("students.txt");

            for (int i = 0; i < students.size(); i++) {
                file << students[i].id << endl;
                file << students[i].name << endl;
                file << students[i].email << endl;
                file << students[i].marks << endl;
                file << "-----" << endl;
            }

            file.close();

            cout << "Students saved to students.txt" << endl;

        } else if (choice == 6) {
            cout << "Program closed" << endl;

        } else {
            cout << "Wrong choice" << endl;
        }

    } while (choice != 6);

    return 0;
}
