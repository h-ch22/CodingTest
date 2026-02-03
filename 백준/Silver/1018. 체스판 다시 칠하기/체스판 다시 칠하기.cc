#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getCount(int x, int y, const vector<string>& board) {
    int countW = 0;
    int countB = 0;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char current = board[x + i][y + j];
            
            if ((i + j) % 2 == 0) {
                if (current != 'W') countW++;
                if (current != 'B') countB++;
            } else {
                if (current != 'B') countW++;
                if (current != 'W') countB++;
            }
        }
    }
    
    return min(countW, countB);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<string> board(n);
    
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    
    int minCount = 64;
    
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            minCount = min(minCount, getCount(i, j, board));
        }
    }
    
    cout << minCount << "\n";
    
    return 0;
}
