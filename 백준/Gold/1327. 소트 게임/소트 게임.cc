#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <unordered_set>

using namespace std;

string vecToString(vector<int>& vec) {
    string s = "";
    
    for(int i: vec) {
        s += to_string(i);
    }
    
    return s;
}

vector<int> stringToVector(string& str) {
    vector<int> v;
    
    for(char c: str) {
        v.emplace_back(c - '0');
    }
    
    return v;
}

void bfs(int start, int k, vector<int>& matrix) {
    vector<int> sortedM = matrix;
    unordered_set<string> visited;
    deque<pair<string, int>> queue;
    
    sort(sortedM.begin(), sortedM.end());

    string matrixAsString = vecToString(matrix);
    string answer = vecToString(sortedM);
    
    visited.insert(matrixAsString);
    queue.emplace_back(make_pair(matrixAsString, 0));
    
    while(!queue.empty()) {
        pair<string, int> front = queue.front();
        queue.pop_front();
        
        string current = front.first;
        
        // cout << current << " -> " << answer << "\n";
        
        if(current == answer) {
            cout << front.second << "\n";
            return;
        }
        
        for(int i = 0; i < matrix.size(); i++) {
            vector<int> tmp = stringToVector(current);
            
            if(i + k - 1 >= tmp.size()) {
                continue;
            }
            
            reverse(tmp.begin() + i, tmp.begin() + i + k);
            
            // for(int t: tmp) {
            //     cout << t << " ";
            // }
            
            // cout << "\n";
            
            string s = vecToString(tmp);

            if(visited.find(s) == visited.end()) {
                visited.insert(s);
                queue.emplace_back(make_pair(s, front.second + 1));
            }
        }
    }
    
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> matrix(n);
    
    for(int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
    
    bfs(0, k, matrix);
    
    return 0;
}
