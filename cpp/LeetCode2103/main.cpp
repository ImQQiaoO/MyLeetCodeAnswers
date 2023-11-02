#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        map<int, string> m;
        int res = 0;
        for (size_t i = 0; i < rings.size() / 2; ++i) {
            m[rings[2 * i + 1] - '0'] += rings[2 * i];
        }
        for (const auto & i : m) {
            if (i.second.find('R') != string::npos && i.second.find('G') != string::npos && i.second.find('B') != string::npos) {
                ++res;
            }
        }
        return res;
    }
};

int main() {
    // rings = "B0B6G0R6R0R6G9"
    Solution s1;
    cout << s1.countPoints("B0B6G0R6R0R6G9") << endl;
    return 0;
}
