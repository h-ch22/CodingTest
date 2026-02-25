#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, MAX));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int num;
            cin >> num;
            
            if(num == 1) {
                graph[i][j] = 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if (graph[j][i] == 1 && graph[i][k] == 1) graph[j][k] = 1;
            }
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << graph[i][j] << " ";
    //     }
        
    //     cout << "\n";
    // }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << (graph[i][j] < MAX && graph[i][j] > 0 ? 1 : 0) << " ";
        }
        
        cout << "\n";
    }
    
    return 0;
}
