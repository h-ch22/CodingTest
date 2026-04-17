#include <string>
#include <vector>
#include <regex>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string answer = "";
    transform(new_id.begin(), new_id.end(), new_id.begin(), [](char c) { return tolower(c); });
    answer = new_id;
    
    regex patternForStep2("[^a-z0-9-_.]");
    answer = regex_replace(new_id, patternForStep2, "");
    
    regex patternForStep3("\\.{2,}");
    answer = regex_replace(answer, patternForStep3, ".");
    
    regex patternForStep4("^\\.|\\.$");
    answer = regex_replace(answer, patternForStep4, "");
    
    if(answer == "") {
        answer = "a";
    }
    
    if(answer.size() >= 16) {
        answer.erase(answer.begin() + 15, answer.end());
        answer = regex_replace(answer, patternForStep4, "");
    }
    
    if(answer.size() < 3) {
        while(answer.size() < 3) {
            answer += answer[answer.size() - 1];
        }
    }
    
    return answer;
}