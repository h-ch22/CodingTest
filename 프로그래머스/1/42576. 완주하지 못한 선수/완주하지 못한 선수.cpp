#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {    
    unordered_map<string, int> um;
    
    for(const string& p: participant) {
        um[p] += 1;
    }
    
    for(const string& c: completion) {
        um[c] -= 1;
    }

    auto answer = find_if(um.begin(), um.end(), [](const auto& it) {        return it.second != 0;
    });
    
    return answer -> first;
}