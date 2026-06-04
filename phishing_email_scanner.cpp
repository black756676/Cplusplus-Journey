#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

string toLowerCase(string text) {
    for (int i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
    }
    return text;
}

int main() {
    ifstream file("emails.txt");
    string line;
    int totalEmails = 0;
    int suspiciousEmails = 0;

    vector<string> suspiciousWords = {
        "urgent", "verify", "password", "login", "free", "gift", "winner", "account"
    };

    if (!file) {
        cout << "emails.txt not found" << endl;
        return 0;
    }

    cout << "===== Phishing Email Scanner =====" << endl;

    while (getline(file, line)) {
        string sender, subject, message;

        stringstream ss(line);
        getline(ss, sender, '|');
        getline(ss, subject, '|');
        getline(ss, message, '|');

        totalEmails++;

        string fullEmail = toLowerCase(sender + " " + subject + " " + message);
        int riskScore = 0;

        if (sender.find("@") == string::npos) {
            riskScore++;
        }

        for (int i = 0; i < suspiciousWords.size(); i++) {
            if (fullEmail.find(suspiciousWords[i]) != string::npos) {
                riskScore++;
            }
        }

        if (riskScore >= 2) {
            suspiciousEmails++;

            cout << endl;
            cout << "Suspicious email found" << endl;
            cout << "Sender: " << sender << endl;
            cout << "Subject: " << subject << endl;
            cout << "Risk score: " << riskScore << endl;
        }
    }

    file.close();

    cout << endl;
    cout << "===== Scan Summary =====" << endl;
    cout << "Total emails checked: " << totalEmails << endl;
    cout << "Suspicious emails found: " << suspiciousEmails << endl;

    return 0;
}
