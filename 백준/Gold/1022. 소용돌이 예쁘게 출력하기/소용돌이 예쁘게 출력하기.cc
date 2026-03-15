#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

void replaceValue(vector<vector<int>>& grid, int x, int y, int maxX, int maxY, int value) {
    if(0 <= x && x < maxX && 0 <= y && y < maxY && grid[y][x] == -1) {
        grid[y][x] = value;
    }
}

int getMax(vector<vector<int>>& grid) {
    int maxVal = 0;
    
    for(vector<int>& g: grid) {
        int maxElem = *max_element(g.begin(), g.end());
        maxVal = max(maxElem, maxVal);
    }
    
    return maxVal;
}

bool isEmptyCellExists(vector<vector<int>>& grid) {
    for(vector<int>& g: grid) {
        auto it = find(g.begin(), g.end(), -1);
        
        if(it != g.end()) {
            return true;
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    
    int maxY = r2 - r1 + 1;
    int maxX = c2 - c1 + 1;
    
    vector<vector<int>> grid(maxY, vector<int>(maxX, -1));
    
    int y = maxY - r2 - 1;
    int x = maxX - c2 - 1;
    int increaseUnit = 1;
    int lastValue = 1;

    replaceValue(grid, x, y, maxX, maxY, 1);
    
    while(isEmptyCellExists(grid)) {
        for(int i = 1; i <= abs(increaseUnit); i++) {
            x += (increaseUnit < 0 ? -1 : 1);
            ++lastValue;
            
            replaceValue(grid, x, y, maxX, maxY, lastValue);
        }
        
        increaseUnit *= -1;
        
        for(int i = 1; i <= abs(increaseUnit); i++) {
            y += (increaseUnit < 0 ? -1 : 1);
            ++lastValue;
            
            replaceValue(grid, x, y, maxX, maxY, lastValue);
        }
        
        increaseUnit = increaseUnit < 0 ? -(abs(increaseUnit) + 1) : (increaseUnit + 1);
    }
    
    int maxVal = getMax(grid);
    
    for(vector<int>& g: grid) {
        for(int i: g) {
            int spaces = to_string(maxVal).size() - to_string(i).size();
            
            for(int j = 0; j < spaces; j++) {
                cout << " ";
            }
            
            cout << i << " ";
        }
        
        cout << "\n";
    }
    
    return 0;
}
