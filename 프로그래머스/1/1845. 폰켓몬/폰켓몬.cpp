#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> us(nums.begin(), nums.end());
    
    return min(us.size(), nums.size() / 2);
}