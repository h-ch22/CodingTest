#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> split(const string& message) {
    stringstream ss(message);
    string word;
    vector<string> words;
    
    while(ss >> word) {
        words.emplace_back(word);
    }
    
    return words;
}

string getStatusMessageByCommand(const string& command) {
    if(command == "Enter") {
        return "님이 들어왔습니다.";
    } else if(command == "Leave") {
        return "님이 나갔습니다.";
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> nickNames;
    vector<vector<string>> parsedRecords;
    
    for(const string& r: record) {
        vector<string> parsed = split(r);
        
        if(parsed.size() == 3) {
            nickNames[parsed[1]] = parsed[2];
        }
        
        parsedRecords.emplace_back(parsed);
    }
    
    for(vector<string> p: parsedRecords) {
        string message = "";
        
        if(p[0] == "Enter" || p[0] == "Leave") {
            message += nickNames[p[1]];
            message += getStatusMessageByCommand(p[0]);
            
            answer.emplace_back(message);
        }
    }
    
    return answer;
}