#include <iostream>

using namespace std;

void printTop(int n) {
    for (int i = 0; i < n; i++) {
        cout << "@";
    }

    for (int i = 0; i < n * 3; i++) {
        cout << " ";
    }

    for (int i = 0; i < n; i++) {
        cout << "@";
    }

    cout << "\n";
}

void printMid(int n) {
    for (int i = 0; i < n; i++) {
        cout << "@";
    }

    for (int i = 0; i < n * 2; i++) {
        cout << " ";
    }

    for (int i = 0; i < n; i++) {
        cout << "@";
    }

    cout << "\n";
}

void printBottom(int n) {
    for (int i = 0; i < n * 3; i++) {
        cout << "@";
    }

    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        printTop(n);
    }

    for (int i = 0; i < n; i++) {
        printMid(n);
    }

    for (int i = 0; i < n; i++) {
        printBottom(n);
    }

    for (int i = 0; i < n; i++) {
        printMid(n);
    }

    for (int i = 0; i < n; i++) {
        printTop(n);
    }

    return 0;
}