#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    vector<vector<int>> sumArr(board.size() + 1, vector<int>(board[0].size() + 1));
    
    for(vector<int>& s: skill) {
        int type = s[0], r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4], degree = s[5];
        if(s[0] == 1) {
            // 공격
            sumArr[r1][c1] += (degree * -1);
            sumArr[r1][c2 + 1] -= (degree * -1);
            sumArr[r2 + 1][c1] -= (degree * -1);
            sumArr[r2 + 1][c2 + 1] += (degree * -1);
        } else {
            // 회복
            sumArr[r1][c1] += degree;
            sumArr[r1][c2 + 1] -= degree;
            sumArr[r2 + 1][c1] -= degree;
            sumArr[r2 + 1][c2 + 1] += degree;
        }
    }
    
    for(int i = 0; i < sumArr.size(); i++) {
        for(int j = 0; j < sumArr[0].size(); j++) {
            if(j - 1 > -1) {
                sumArr[i][j] += sumArr[i][j - 1];
            }
        }
    }
    
    for(int i = 0; i < sumArr.size(); i++) {
        for(int j = 0; j < sumArr[0].size(); j++) {
            if(i - 1 > -1) {
                sumArr[i][j] += sumArr[i - 1][j];
            }
        }
    }
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            board[i][j] += sumArr[i][j];
            
            if(board[i][j] > 0) {
                answer++;
            }
        }
    }
    
    return answer;
}