#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> matrix(n);

    for(int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
    
    int maxSum = -100000000;
    int partialMax = maxSum;
    
    for(int i: matrix) {
        partialMax = max(partialMax + i, i);
        
        if(partialMax > maxSum) {
            maxSum = partialMax;
        }
    }
    
    cout << maxSum << "\n";
    
    return 0;
}
