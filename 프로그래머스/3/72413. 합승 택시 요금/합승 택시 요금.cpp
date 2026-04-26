#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define MAX 100000000

using namespace std;

vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& nodes) {
    vector<int> dist(n + 1, MAX);
    priority_queue<pair<int, int>> pq;
    
    dist[start] = 0;
    
    pq.push({ 0, start });
    
    while(!pq.empty()) {
        int cost = -pq.top().first, current = pq.top().second;
        pq.pop();
        
        if(dist[current] < cost) continue;
        
        for(int i = 0; i < nodes[current].size(); i++) {
            int toCost = nodes[current][i].second, to = nodes[current][i].first, viaCost = cost + toCost;
            
            if(viaCost < dist[to]) {
                dist[to] = viaCost;
                pq.push({ -viaCost, to });
            }
        }
    }
    
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = MAX;
    vector<vector<pair<int, int>>> nodes(n + 1);
    
    for(const vector<int>& f: fares) {
        nodes[f[0]].emplace_back(f[1], f[2]);
        nodes[f[1]].emplace_back(f[0], f[2]);
    }
    
    vector<int> distS = dijkstra(s, n, nodes);
    vector<int> distA = dijkstra(a, n, nodes);
    vector<int> distB = dijkstra(b, n, nodes);
        
    for(int k = 1; k <= n; k++) {
        answer = min(answer, distS[k] + distA[k] + distB[k]);
    }
    
    return answer;
}