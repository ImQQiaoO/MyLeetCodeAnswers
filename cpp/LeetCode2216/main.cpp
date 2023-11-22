#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletion(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        stack<int> stk;
        stk.push(nums[0]);
        for (size_t i = 1; i < n ; ++i) {
            if (stk.size() % 2 == 0) {
                stk.push(nums[i]);
            } else {
                if (nums[i] == stk.top()) {
                    continue;
                }
                stk.push(nums[i]);
            }
        }
        if (stk.size() % 2) return n - stk.size() + 1;
        return n - stk.size();
    }
};

int main() {
    // nums = [1,1,2,3,5]
    Solution s0;
    vector<int> nums0{1, 1, 2, 3, 5};
    cout << s0.minDeletion(nums0) << endl;

    // nums = [1,1,2,2,3,3]
    Solution s1;
    vector<int> nums1{1, 1, 2, 2, 3, 3};
    cout << s1.minDeletion(nums1) << endl;
    return 0;
}
