#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> us(phone_book.begin(), phone_book.end());
    
    for(const auto& s: us) {
        for(int i = 1; i < s.size(); i++) {
            if(us.find(s.substr(0, i)) != us.end()) {
                return false;
            }
        }
    }
    
    return true;
}