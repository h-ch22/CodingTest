#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    vector<string> result;
    set_difference(participant.begin(), participant.end(), completion.begin(), completion.end(), std::back_inserter(result));
    
    answer = result[0];
        
    return answer;
}