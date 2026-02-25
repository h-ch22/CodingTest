#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#define MAX 100000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> friends(n + 1, vector<int>(n + 1, MAX));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                friends[i][j] = 0;
            }
        }
    }
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        friends[a][b] = 1;
        friends[b][a] = 1;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                friends[j][k] = min(friends[j][k], friends[j][i] + friends[i][k]);
            }
        }
    }
    
    vector<int> dist(n + 1, MAX);
    
    for(int i = 1; i <= n; i++) {
        dist[i] = accumulate(friends[i].begin() + 1, friends[i].end(), 0);
    }
    
    int answer = min_element(dist.begin(), dist.end()) - dist.begin();
    cout << answer << "\n";
    
    return 0;
}