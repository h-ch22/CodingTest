#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string num;
    cin >> num;

    sort(num.begin(), num.end(), greater<int>());
    cout << num << "\n";

    return 0;
}