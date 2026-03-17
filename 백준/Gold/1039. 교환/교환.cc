#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<vector<bool>> visited(11, vector<bool>(1000001));
    
    deque<pair<int, int>> queue;
    queue.emplace_back(make_pair(n, 0));
    
    while(!queue.empty()) {
        string current = to_string(queue.front().first);
        int op = queue.front().second;
        queue.pop_front();
        
        if(op == k) {
            continue;
        }
        
        for(int i = 0; i < current.size(); i++) {
            for(int j = i + 1; j < current.size(); j++) {
                string currentCopy = current;
                swap(currentCopy[i], currentCopy[j]);

                if(currentCopy[0] != '0' && !visited[op + 1][stoi(currentCopy)]) {
                    visited[op + 1][stoi(currentCopy)] = true;
                    queue.emplace_back(make_pair(stoi(currentCopy), op + 1));
                }
            }
        }
    }
    
    auto it = find_if(visited[k].rbegin(), visited[k].rend(), [](bool v) {
        return v;
    });
    
    if(it != visited[k].rend()) {
        cout << distance(visited[k].begin(), it.base() - 1) << "\n";
    } else {
        cout << -1 << "\n";
    }
    
    return 0;
}
