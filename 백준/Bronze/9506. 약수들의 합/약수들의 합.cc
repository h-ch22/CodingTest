#include <iostream>
#include <string>
#include <vector>

using namespace std;

void detectPerfectNum(int num) {
    int sum = 0;
    vector<int> divisors;

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
            divisors.push_back(i);
        }
    }

    if (sum == num) {
        cout << num << " = ";

        for (int i = 0; i < divisors.size(); i++) {
            cout << divisors[i];

            if (i < divisors.size() - 1) {
                cout << " + ";
            }
        }

        cout << "\n";
    } else {
        cout << num << " is NOT perfect.\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;

    while (true) {
        cin >> num;

        if (num == -1) {
            break;
        }

        detectPerfectNum(num);
    }

    return 0;
}
