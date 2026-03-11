#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> prevMax(3);
    vector<int> prevMin(3);
    vector<int> currMax(3);
    vector<int> currMin(3);
    
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if(i == 0) {
            prevMax[0] = prevMin[0] = a;
            prevMax[1] = prevMin[1] = b;
            prevMax[2] = prevMin[2] = c;
            
            continue;
        }
        
        currMax[0] = a + max(prevMax[0], prevMax[1]);
        currMax[1] = b + *max_element(prevMax.begin(), prevMax.end());
        currMax[2] = c + max(prevMax[1], prevMax[2]);
        
        currMin[0] = a + min(prevMin[0], prevMin[1]);
        currMin[1] = b + *min_element(prevMin.begin(), prevMin.end());
        currMin[2] = c + min(prevMin[1], prevMin[2]);
        
        prevMin = currMin;
        prevMax = currMax;
    }
    
    int maxElem = *max_element(prevMax.begin(), prevMax.end());
    int minElem = *min_element(prevMin.begin(), prevMin.end());
    
    cout << maxElem << " " << minElem << "\n";
    
    return 0;
}
