#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 贪心
    int maxSubArray(vector<int> &nums) {
        int ans = INT_MIN;

        int sum = 0;

        for (size_t i = 0; i != nums.size(); ++i) {
            // int temp = 0; // 超时
            // for (size_t j = i; j != nums.size(); ++j) {
            //     temp += nums[j];
            //     max = std::max(max, temp);
            // }
            sum += nums[i];
            ans = std::max(sum, ans);
            if (sum < 0) sum = 0;   // 如果前边的数字的和是负数，直接扔掉

        }
        return ans;
    }
};

int main() {
    // nums = [-2,1,-3,4,-1,2,1,-5,4]
    Solution s0;
    vector<int> nums0 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s0.maxSubArray(nums0) << endl;

    // nums = [1]
    Solution s1;
    vector<int> nums1 = {1};
    cout << s1.maxSubArray(nums1) << endl;

    // nums = [5,4,-1,7,8]
    Solution s2;
    vector<int> nums2 = {5, 4, -1, 7, 8};
    cout << s2.maxSubArray(nums2) << endl;
    return 0;
}
