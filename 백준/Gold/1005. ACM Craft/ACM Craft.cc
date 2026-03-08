#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

#define MAX 999999999

using namespace std;

void topologySort(vector<vector<int>>& graph, vector<int>& inDegree, vector<int>& times, int W) {
    int n = graph.size();
    
    deque<int> queue;
    vector<int> dp(n + 1);

    for(int i = 0; i < n; i++) {
        if(inDegree[i] == 0) {
            dp[i] = times[i];
            queue.emplace_back(i);
        }
    }
    
    for(int i = 0; i < n; i++) {
        int current = queue.front();
        queue.pop_front();
        
        for(int g: graph[current]) {
            dp[g] = max(dp[current] + times[g], dp[g]);

            if(--inDegree[g] == 0) {
                queue.emplace_back(g);

//                cout << dp[current] << "(" << current << ")" << " -> " << times[g] << "(" << g << ")" << "\n";
                
            }
        }
    }
    
    cout << dp[W] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> times(N + 1);
        vector<vector<int>> graph(N + 1);
        vector<int> inDegree(N + 1);
        
        for(int i = 1; i <= N; i++) {
            cin >> times[i];
        }
        
        for(int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            
            graph[a].emplace_back(b);
            inDegree[b]++;
        }
        
        int W;
        cin >> W;
        
        topologySort(graph, inDegree, times, W);
    }
    
    return 0;
}
