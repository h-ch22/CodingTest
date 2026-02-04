#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Member {
public:
    int age;
    int index;
    string name;

    Member(): age(0), index(0), name("") {}
    Member(int age, int index, const string& name) {
        this->age = age;
        this->index = index;
        this->name = name;
    }

    bool operator <(const Member& other) const {
        if (this->age != other.age) {
            return this->age < other.age;
        }

        return this->index < other.index;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Member> members(n);

    for (int i = 0; i < n; i++) {
        cin >> members[i].age >> members[i].name;
        members[i].index = i;
    }

    sort(members.begin(), members.end());

    for (Member member: members) {
        cout << member.age << " " << member.name << "\n";
    }

    return 0;
}
