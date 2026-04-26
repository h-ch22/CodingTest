#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, -1);
    unordered_set<string> gemSet(gems.begin(), gems.end());
    unordered_map<string, int> gemMap;
    gemMap[gems[0]]++;
    
    int start = 0, end = 0;
    
    while(start <= end) {
        if(end >= gems.size()) {
            break;
        }
        
        if(end - start < gemSet.size() - 1 || gemMap.size() < gemSet.size()) {
            end++;
            
            if(end < gems.size()) {
                gemMap[gems[end]]++;
            }
        } else {
            int currentStart = answer[0], currentEnd = answer[1], currentRange = answer[1] - answer[0], range = end - start;
            if(currentStart == -1 || currentEnd == -1 || currentRange > range || (currentRange >= range && currentStart > start + 1)) {
                answer[0] = start + 1;
                answer[1] = end + 1;
            }
            
            gemMap[gems[start]]--;
            
            if(gemMap[gems[start]] == 0) {
                gemMap.erase(gems[start]);
            }
            
            start++;
        }
    }
    
    return answer;
}