#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;
    
    for(const vector<string>& s: clothes) {
        um[s[1]]++;
    }
    
    for(const auto& [key, value]: um) {
        answer *= (value + 1);
    }
    
    return answer - 1;
}