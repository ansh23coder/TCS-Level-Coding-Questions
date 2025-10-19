// https://www.hackerrank.com/contests/oriental-campus-181025/challenges/tower-of-cubes/problem

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int minTowers(const vector<int>& boxes) {
    multiset<int> tops; // will hold the top values of towers

    for (int box : boxes) {
        auto it = tops.upper_bound(box); // find first tower top > box

        if (it != tops.end()) {
            tops.erase(it); // replace this tower's top
        }

        tops.insert(box); // push this box as a new/updated top
    }

    return tops.size(); // number of towers
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string line;
        getline(cin, line);
        vector<int> boxes;
        int num = 0;
        for (char ch : line) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == ' ') {
                boxes.push_back(num);
                num = 0;
            }
        }
        if (!line.empty())
            boxes.push_back(num); // push last number

        cout << minTowers(boxes) << endl;
    }

    return 0;
}
