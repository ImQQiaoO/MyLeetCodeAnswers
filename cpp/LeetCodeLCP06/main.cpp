#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCount(vector<int> &coins) {
        int res = 0;
        for (int coin : coins) {
            if (coin % 2 == 0) {
                res += coin / 2;
            } else {
                res += coin / 2 + 1;
            }
        }
        return res;
    }
};

int main() {
    // [4,2,1]
    Solution s;
    vector<int> coins = {4, 2, 1};
    cout << s.minCount(coins) << endl;

    // [2,3,10]
    Solution s1;
    vector<int> coins1 = {2, 3, 10};
    cout << s1.minCount(coins1) << endl;
    return 0;
}
