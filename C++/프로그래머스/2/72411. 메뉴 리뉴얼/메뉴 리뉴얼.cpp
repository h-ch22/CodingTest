#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
        
    for(int c: course) {
        map<string, int> menuMap;

        for(string& o: orders) {
            if(o.size() >= c) {
                sort(o.begin(), o.end());
                vector<int> mask(o.size(), 0);
                fill(mask.end() - c, mask.end(), 1);

                do {
                    string newMenu = "";

                    for(int i = 0; i < o.size(); i++) {
                        if(mask[i] == 1) {
                            newMenu += o[i];        
                        }
                    }

                    menuMap[newMenu]++;
                } while(next_permutation(mask.begin(), mask.end()));
            }
        }
        
        auto maxValue = max_element(menuMap.begin(), menuMap.end(),
            [](const auto& p1, const auto& p2) {
                return p1.second < p2.second;
            }
        );

        for(const auto& [key, value]: menuMap) {
            if(value == maxValue->second && value >= 2) {
                answer.emplace_back(key);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}