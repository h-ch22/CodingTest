#include <iostream>
#include <string>

using namespace std;

struct ScoreForm {
    string lectureName;
    double credit;
    string score;
};

double to_int(string score) {
    if (score == "A+") {
        return 4.5;
    }
    if (score == "A0") {
        return 4.0;
    }
    if (score == "B+") {
        return 3.5;
    }
    if (score == "B0") {
        return 3.0;
    }
    if (score == "C+") {
        return 2.5;
    }
    if (score == "C0") {
        return 2.0;
    }
    if (score == "D+") {
        return 1.5;
    }
    if (score == "D0") {
        return 1.0;
    }
    if (score == "F") {
        return 0.0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ScoreForm scores[20] = {};

    for (int i = 0; i < 20; i++) {
        cin >> scores[i].lectureName >> scores[i].credit >> scores[i].score;
    }

    double sumOfCredits = 0;
    double sumOfScores = 0;

    for (ScoreForm score: scores) {
        if (score.score != "P") {
            sumOfCredits += score.credit;
            sumOfScores += score.credit * to_int(score.score);
        }
    }

    cout << sumOfScores / sumOfCredits;

    return 0;
}
