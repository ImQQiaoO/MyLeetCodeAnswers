#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int result = 0;
        for (auto &num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main() {
    puts("-----------------test------------------");
    int a = 10, b = 10, c = 20;
    cout << (a ^ b ^ c) << endl;    // 异或
    puts("---------------------------------------");
    Solution s0;
    vector<int> nums = {2, 2, 1};
    cout << s0.singleNumber(nums) << endl;

    Solution s1;
    nums = {4, 1, 2, 1, 2};
    cout << s1.singleNumber(nums) << endl;

    Solution s2;
    nums = {1};
    cout << s2.singleNumber(nums) << endl;
    return 0;
}
