#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> parseRecord(const string& record) {
    stringstream ss(record);
    string word;
    vector<string> words;
    
    while(ss >> word) {
        words.emplace_back(word);
    }
    
    return words;
}

int parseTime(const string& start, const string& end) {
    stringstream ss_start(start);
    stringstream ss_end(end);
    
    string segment;
    vector<int> startTime;
    vector<int> endTime;
    
    while(getline(ss_start, segment, ':')) {
        startTime.emplace_back(stoi(segment));
    }
    
    while(getline(ss_end, segment, ':')) {
        endTime.emplace_back(stoi(segment));
    }
        
    if(startTime[0] == endTime[0]) {
        return endTime[1] - startTime[1];
    } else if(endTime[0] - startTime[0] == 1 && endTime[1] == 0) {
        return 60 - startTime[1];
    } else {
        int diffHours = (endTime[0] - startTime[0]) * 60;
        int diffMinutes;
        
        if(endTime[1] == 0) {
            diffMinutes = 60 - startTime[1];
        } else {
            diffMinutes = max(endTime[1] - startTime[1], startTime[1] - endTime[1]);
        }
        
        return diffHours + diffMinutes;
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> logs;
    
    for(const string& r: records) {
        vector<string> log = parseRecord(r);
        
        logs[log[1]].emplace_back(log[0]);
    }
    
    for(const auto& pair: logs) {
        if(pair.second.size() == 1) {
            logs[pair.first].emplace_back("23:59");
        }
        
        int eta = parseTime(pair.second[0], pair.second[1]);
        cout << pair.first << " -> " << pair.second[0] << " - " << pair.second[1] << " = " << eta << " -> ";
        if(eta <= fees[0]) {
            answer.emplace_back(fees[1]);
            cout << fees[1] << "\n";
        } else {
            int fee = fees[1];
            double extraFee = ceil((eta - fees[2]) / 10) * fees[3];
            answer.emplace_back(fee + extraFee);
            cout << fee + extraFee << "\n";
        }
    }
    
    return answer;
}