#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

int main() {
    ifstream blockFile("blocked_ips.txt");
    ifstream logFile("access_logs.txt");

    set<string> blockedIps;
    string ip;

    int totalLogs = 0;
    int blockedHits = 0;

    if (!blockFile) {
        cout << "blocked_ips.txt not found" << endl;
        return 0;
    }

    if (!logFile) {
        cout << "access_logs.txt not found" << endl;
        return 0;
    }

    while (getline(blockFile, ip)) {
        blockedIps.insert(ip);
    }

    blockFile.close();

    cout << "===== IP Blocklist Checker =====" << endl;

    string line;

    while (getline(logFile, line)) {
        string time;
        string visitorIp;
        string path;
        int statusCode;

        stringstream ss(line);
        ss >> time >> visitorIp >> path >> statusCode;

        totalLogs++;

        if (blockedIps.find(visitorIp) != blockedIps.end()) {
            blockedHits++;

            cout << endl;
            cout << "Blocked IP activity found" << endl;
            cout << "IP: " << visitorIp << endl;
            cout << "Path: " << path << endl;
            cout << "Status Code: " << statusCode << endl;
        }
    }

    logFile.close();

    cout << endl;
    cout << "===== Scan Summary =====" << endl;
    cout << "Total logs checked: " << totalLogs << endl;
    cout << "Blocked IP hits: " << blockedHits << endl;

    return 0;
}
