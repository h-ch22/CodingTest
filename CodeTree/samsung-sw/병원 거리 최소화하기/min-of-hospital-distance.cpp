#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define INF 9999999

using namespace std;

int minDistance = INF;

void calculateDistance(const vector<vector<int>>& grid, const vector<pair<int, int>>& hospitals, const vector<pair<int, int>>& houses) {
    int distance = 0;

    for(int i = 0; i < houses.size(); i++) {
        int distanceForCurrentHouse = INF;
        int houseY = houses[i].first, houseX = houses[i].second;

        for(int j = 0; j < hospitals.size(); j++) {
            int hospitalY = hospitals[j].first, hospitalX = hospitals[j].second;

            distanceForCurrentHouse = min(distanceForCurrentHouse, abs(houseX - hospitalX) + abs(houseY - hospitalY));
        }

        distance += distanceForCurrentHouse;
    }

    minDistance = min(minDistance, distance);
}

void closeHospital(vector<vector<int>>& grid, vector<pair<int, int>>& hospitals, const vector<pair<int, int>>& houses, const int m, int idx, int count) {    
    if(hospitals.size() == m) {
        calculateDistance(grid, hospitals, houses);
        return;
    }

    for(int i = idx; i < hospitals.size(); i++) {
        const int y = hospitals[i].first;
        const int x = hospitals[i].second;
        
        grid[y][x] = 0;
        hospitals.erase(hospitals.begin() + i);
        closeHospital(grid, hospitals, houses, m, i, count + 1);
        hospitals.insert(hospitals.begin() + i, { y, x });
        grid[y][x] = 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 0: 빈 칸, 1: 사람, 2: 병원
    vector<vector<int>> grid(n, vector<int>(n));
    vector<pair<int, int>> hospitals;
    vector<pair<int, int>> houses;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int f;
            cin >> f;

            grid[i][j] = f;

            if(f == 1) {
                houses.emplace_back(i, j);
            } else if(f == 2) {
                hospitals.emplace_back(i, j);
            }
        }
    }

    closeHospital(grid, hospitals, houses, m, 0, 0);
    cout << minDistance << "\n";

    return 0;
}