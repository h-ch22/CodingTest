#include <iostream>
#include <vector>
#include <deque>

typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll a, b;
    cin >> a >> b;
    
    deque<pair<ll, ll>> queue;
    queue.emplace_back(make_pair(a, 1));
    
    while(!queue.empty()) {
        pair<ll, ll> fr = queue.front();
        ll next = fr.first;
        ll count = fr.second;
        
        queue.pop_front();
        
        if(next == b) {
            cout << count << "\n";
            return 0;
        }
        
        ll nextA = next * 2;
        ll nextB = next * 10 + 1;
        
        // cout << "From: " << next << " To: " << nextA << ", " << nextB << "\n";
        
        if(nextA <= b) {
            queue.emplace_back(make_pair(nextA, count + 1));
        }
        
        if(nextB <= b) {
            queue.emplace_back(make_pair(nextB, count + 1));
        }
    }
    
    cout << -1 << "\n";
    
    return 0;
}
