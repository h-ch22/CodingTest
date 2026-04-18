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

double parseTime(const string& start, const string& end) {
    stringstream ss_start(start);
    stringstream ss_end(end);
    
    string segment;
    vector<double> startTime;
    vector<double> endTime;
        
    while(getline(ss_start, segment, ':')) {
        startTime.emplace_back(stod(segment));
    }
    
    while(getline(ss_end, segment, ':')) {
        endTime.emplace_back(stod(segment));
    }
        
    if(startTime[0] == endTime[0]) {
        return endTime[1] - startTime[1];
    } else if(endTime[1] == startTime[1]) {
        return (endTime[0] - startTime[0]) * 60;
    } else if(endTime[0] - startTime[0] == 1 && endTime[1] == 0) {
        return 60 - startTime[1];
    } else {
        double diffHours = (endTime[0] - startTime[0]) * 60;
        double diffMinutes;
        
        if(endTime[1] == 0) {
            diffMinutes = 60 - startTime[1];
            diffHours -= 60;
        } else {
            if(endTime[1] < startTime[1]) {
                endTime[1] += 60;
                diffHours -= 60;
            }
            
            diffMinutes = endTime[1] - startTime[1];
        }
                
        return diffHours + diffMinutes;
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> logs;
    
    for(const string& r: records) {
        vector<string> log = parseRecord(r);
        
        if(log[2] == "IN" && logs[log[1]].size() % 2 != 0) {
            logs[log[1]].emplace_back("23:59");
        }
        
        logs[log[1]].emplace_back(log[0]);
    }
    
    for(const auto& pair: logs) {
        double eta = 0;
        
        if(pair.second.size() % 2 != 0) {
            logs[pair.first].emplace_back("23:59");
        }
        
        for(int i = 0; i < pair.second.size(); i+=2) {
            eta += parseTime(pair.second[i], pair.second[i+1]);
        }
        
        if(eta <= fees[0]) {
            answer.emplace_back(fees[1]);
        } else {
            int fee = fees[1];
            double extraFee = ceil((eta - fees[0]) / fees[2]) * fees[3];
            answer.emplace_back(fee + static_cast<int>(extraFee));
        }
    }
    
    return answer;
}