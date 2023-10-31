#include <iostream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int x = 1, y = 0;
        for (char c : s) {
            if (c == 'A') {
                x = 2 * x + y;
            }
            if (c == 'B') {
                y = 2 * y + x;
            }
        }
        return x + y;
    }
};
int main() {
    Solution s1;
    cout << s1.calculate("AB") << endl;
    return 0;
}
