#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genre_plays;
    unordered_map<string, vector<pair<int, int>>> genre_songs;
    
    for(int i = 0; i < genres.size(); i++) {
        genre_plays[genres[i]] += plays[i];
        genre_songs[genres[i]].emplace_back(make_pair(plays[i], i));
    }
    
    vector<pair<string, int>> sortedGenrePlaysMap(genre_plays.begin(), genre_plays.end());
    
    sort(sortedGenrePlaysMap.begin(), sortedGenrePlaysMap.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    
    vector<string> sortedGenrePlays;
    
    for(const auto& p: sortedGenrePlaysMap) {
        sortedGenrePlays.emplace_back(p.first);
    }
    
    for(const string& genre: sortedGenrePlays) {
        sort(genre_songs[genre].begin(), genre_songs[genre].end(), [](const auto& a, const auto& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            
            return a.second < b.second;
        });
        
        for(int i = 0; i < min(2, static_cast<int>(genre_songs[genre].size())); i++) {
            answer.emplace_back(genre_songs[genre][i].second);
        }
    }
    
    return answer;
}