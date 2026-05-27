#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    float marks;
};

int main() {
    vector<Student> students;
    Student temp;
    int n;

    cout << "===== Student Record System =====" << endl;

    cout << "How many students? ";
    cin >> n;

    cin.ignore();

    if (n <= 0) {
        cout << "Invalid number of students" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << endl;
        cout << "Enter student " << i + 1 << " details" << endl;

        cout << "Name: ";
        getline(cin, temp.name);

        cout << "Age: ";
        cin >> temp.age;

        cout << "Marks: ";
        cin >> temp.marks;

        cin.ignore();

        students.push_back(temp);
    }

    cout << endl;
    cout << "===== Student Records =====" << endl;

    for (int i = 0; i < students.size(); i++) {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Marks: " << students[i].marks << endl;
        cout << endl;
    }

    int highestIndex = 0;

    for (int i = 1; i < students.size(); i++) {
        if (students[i].marks > students[highestIndex].marks) {
            highestIndex = i;
        }
    }

    cout << "===== Top Student =====" << endl;
    cout << "Name: " << students[highestIndex].name << endl;
    cout << "Marks: " << students[highestIndex].marks << endl;

    return 0;
}
