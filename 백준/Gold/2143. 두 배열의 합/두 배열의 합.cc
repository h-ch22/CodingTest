#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n, m;
	cin >> T >> n;

	vector<int> A(n);

	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cin >> m;

	vector<int> B(m);

	for(int i = 0; i < m; i++) {
		cin >> B[i];
	}

	vector<int> sumA;
	vector<int> sumB;

	for(int i = 0; i < n; i++) {
	    int currentSum = 0;
	    
		for(int j = i; j < n; j++) {
			currentSum += A[j];
			sumA.emplace_back(currentSum);
		}
	}

	for(int i = 0; i < m; i++) {
	    int currentSum = 0;
	    
		for(int j = i; j < m; j++) {
		    currentSum += B[j]; 
			sumB.emplace_back(currentSum);
		}
	}

	long long count = 0;

	sort(sumA.begin(), sumA.end());
	sort(sumB.begin(), sumB.end());

	for(int i = 0; i < sumA.size(); i++) {
		int temp = T - sumA[i];

        auto lbB = lower_bound(sumB.begin(), sumB.end(), temp);
        auto ubB = upper_bound(sumB.begin(), sumB.end(), temp);
        
        count += (ubB - lbB);
	}

	cout << count << "\n";

	return 0;
}
