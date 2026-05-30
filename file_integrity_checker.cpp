#include <iostream>//LETS GOO---
#include <fstream>
#include <string>
using namespace std;

long long calculateChecksum(string fileName) {
    ifstream file(fileName, ios::binary);
    char ch;
    long long checksum = 0;

    if (!file) {
        return -1;
    }

    while (file.get(ch)) {
        checksum = checksum + (unsigned char)ch;
    }

    file.close();
    return checksum;
}

int main() {
    int choice;
    string fileName;

    cout << "===== File Integrity Checker =====" << endl;
    cout << "1. Save file fingerprint" << endl;
    cout << "2. Check file integrity" << endl;
    cout << "Choice: ";
    cin >> choice;

    cout << "Enter file name: ";
    cin >> fileName;

    long long currentChecksum = calculateChecksum(fileName);

    if (currentChecksum == -1) {
        cout << "File not found" << endl;
        return 0;
    }

    if (choice == 1) {
        ofstream outFile("fingerprint.txt");

        outFile << fileName << endl;
        outFile << currentChecksum << endl;

        outFile.close();

        cout << "File fingerprint saved successfully" << endl;

    } else if (choice == 2) {
        ifstream inFile("fingerprint.txt");

        string savedFileName;
        long long savedChecksum;

        if (!inFile) {
            cout << "No saved fingerprint found" << endl;
            return 0;
        }

        getline(inFile, savedFileName);
        inFile >> savedChecksum;

        inFile.close();

        if (fileName == savedFileName && currentChecksum == savedChecksum) {
            cout << "File is safe. No changes detected." << endl;
        } else {
            cout << "Warning! File has been changed." << endl;
        }

    } else {
        cout << "Wrong choice" << endl;
    }

    return 0;
}
