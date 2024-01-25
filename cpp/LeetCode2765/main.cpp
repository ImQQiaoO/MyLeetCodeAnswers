#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int alternatingSubarray(vector<int> &nums) {
        int diff = 1;
        int res = 0;
        auto l = nums.begin();	// 左指针
        int temp_res = 1;
        int pointer_holder = 0;
        while (l != nums.end() - 1) {
            if (*(l + 1) - *l == diff) {
                ++temp_res;
                ++l;
                pointer_holder = 0;
            } else {
                if (pointer_holder == 1) {
                    ++l;
                    pointer_holder = 0;
                    //continue;
                }
                ++pointer_holder;
                res = std::max(res, temp_res);
                temp_res = 1;
                diff = -1;
            }
            diff = -diff;
        }
        res = std::max(res, temp_res);
        return res == 1 ? -1 : res;
    }
};


int main() {

    // nums = [2,3,4,3,4]
    Solution s0;
    vector<int> nums0 = {2, 3, 4, 3, 4};
    int res = s0.alternatingSubarray(nums0);
    cout << res << endl;

    // nums = [4,5,6]
    Solution s1;
    vector<int> nums1 = {4, 5, 6};
    int res1 = s1.alternatingSubarray(nums1);
    cout << res1 << endl;

    // nums = [1,2,1,2,1]
    Solution s2;
    vector<int> nums2 = {1, 2, 1, 2, 1};
    int res2 = s2.alternatingSubarray(nums2);
    cout << res2 << endl;

    // nums = [21, 9, 5]
    Solution s3;
    vector<int> nums3 = {21, 9, 5};
    int res3 = s3.alternatingSubarray(nums3);
    cout << res3 << endl;

    // nums = [51, 52, 53, 52, 53, 52, 53, 54, 53], ans = 6
    Solution s4;
    vector<int> nums4 = {51, 52, 53, 52, 53, 52, 53, 54, 53};
    int res4 = s4.alternatingSubarray(nums4);
    cout << res4 << endl;

    // nums = [50,51,52,53,52,53], ans = 4
    Solution s5;
    vector<int> nums5 = {50, 51, 52, 53, 52, 53};
    int res5 = s5.alternatingSubarray(nums5);
    cout << res5 << endl;

    return 0;
}
