#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

struct teamInfo {
    int solutions = 0;
    int totalTime = 0;
};

int TTS(const string& timeStr) {
    int hours, minutes, seconds;
    sscanf(timeStr.c_str(), "%d:%d:%d", &hours, &minutes, &seconds);
    return hours * 3600 + minutes * 60 + seconds;
}

void Res(map<string, teamInfo>& teams, const string& teamName, const string& result, int timeSpent) {
    if (result == "ACCESSED") {
        teams[teamName].solutions += 1;
        teams[teamName].totalTime += timeSpent;
    } else if (result == "FORBIDEN" || result == "DENIED") {
        teams[teamName].totalTime += 20 * 60;
    }
}

bool cmp(const pair<string, teamInfo>& a, const pair<string, teamInfo>& b) {
    if (a.second.solutions != b.second.solutions)
        return a.second.solutions > b.second.solutions;
    if (a.second.totalTime != b.second.totalTime)
        return a.second.totalTime < b.second.totalTime;
    return a.first < b.first;
}

int main() {
    string startTimeStr;
    int n;
    cin >> startTimeStr >> n;
    cin.ignore();

    int startTime = TTS(startTimeStr);

    map<string, teamInfo> teams;
    for (int i = 0; i < n; i++) {
        string hackStr;
        getline(cin, hackStr);
        string teamName, result, serverName, timeSpentStr;
        stringstream hackStream(hackStr);
        hackStream >> teamName >> timeSpentStr >> serverName >> result;
        int timeSpent = TTS(timeSpentStr) - startTime;
        if (timeSpent < 0) {
            timeSpent += 24 * 3600;
        }
        Res(teams, teamName, result, timeSpent);
    }

    vector<pair<string, teamInfo>> winTable(teams.begin(), teams.end());

    sort(winTable.begin(), winTable.end(), cmp);

    int place = 1;
    for (size_t i = 0; i < winTable.size(); ++i) {
        if (i > 0 && (winTable[i].second.solutions != winTable[i - 1].second.solutions ||
                      winTable[i].second.totalTime != winTable[i - 1].second.totalTime)) {
            place = i + 1;
        }
        cout << place << " " << winTable[i].first
             << " " << winTable[i].second.solutions
             << " " << winTable[i].second.totalTime / 60 << '\n';
    }

    return 0;
}