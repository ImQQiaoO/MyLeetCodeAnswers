#include <iostream>

using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int t = time % (n - 1);
        return time / (n - 1) % 2 ? n - t : 1 + t;
    }
};

int main() {
    Solution s0;
    cout << s0.passThePillow(4, 5) << endl;
    Solution s1;
    cout << s1.passThePillow(3, 2) << endl;
    return 0;
}
