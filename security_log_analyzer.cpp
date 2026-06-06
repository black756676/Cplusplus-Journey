#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

struct IpStats {
    int totalRequests = 0;
    int failedRequests = 0;
    int notFoundRequests = 0;
    int sensitiveRequests = 0;
};

int main() {
    ifstream file("security_logs.txt");
    map<string, IpStats> ipRecords;

    string line;
    int totalLogs = 0;

    if (!file) {
        cout << "security_logs.txt not found" << endl;
        return 0;
    }

    while (getline(file, line)) {
        string timestamp;
        string ip;
        string path;
        int statusCode;

        stringstream ss(line);

        if (!(ss >> timestamp >> ip >> statusCode >> path)) {
            cout << "Skipped invalid log line" << endl;
            continue;
        }

        totalLogs++;
        ipRecords[ip].totalRequests++;

        if (statusCode == 401 || statusCode == 403) {
            ipRecords[ip].failedRequests++;
        }

        if (statusCode == 404) {
            ipRecords[ip].notFoundRequests++;
        }

        if (path == "/admin" || path == "/login") {
            ipRecords[ip].sensitiveRequests++;
        }
    }

    file.close();

    cout << "===== Security Log Report =====" << endl;
    cout << "Total logs checked: " << totalLogs << endl;

    for (const auto& record : ipRecords) {
        string ip = record.first;
        IpStats stats = record.second;
        int riskScore = 0;

        if (stats.failedRequests >= 3) {
            riskScore += 3;
        }

        if (stats.notFoundRequests >= 3) {
            riskScore += 2;
        }

        if (stats.sensitiveRequests >= 2) {
            riskScore += 2;
        }

        cout << endl;
        cout << "IP Address: " << ip << endl;
        cout << "Total requests: " << stats.totalRequests << endl;
        cout << "Failed requests: " << stats.failedRequests << endl;
        cout << "Not found requests: " << stats.notFoundRequests << endl;
        cout << "Risk score: " << riskScore << endl;

        if (riskScore >= 5) {
            cout << "Status: High risk - review required" << endl;
        } else if (riskScore >= 2) {
            cout << "Status: Medium risk" << endl;
        } else {
            cout << "Status: Normal" << endl;
        }
    }

    return 0;
}
