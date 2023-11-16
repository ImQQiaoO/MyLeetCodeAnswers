#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int> &nums, int threshold) {
        int max_length = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 != 0) {
                continue;
            }
            int curr_len = 0;
            for (size_t j = i; j < nums.size(); ++j) {
                if (nums.size() == 1) {
                    if (nums[0] > threshold) {
                        return 0;
                    }
                    ++curr_len;
                    break;
                }
                if (j == nums.size() - 1 && nums[j] % 2 == 0 && nums[j - 1] % 2 == 0
                    && nums[j] <= threshold) {
                    ++curr_len;
                }
                if (j == nums.size() - 1 && (nums[j] % 2 != nums[j - 1] % 2
                    && nums[j] <= threshold)) {
                    ++curr_len;
                }
                if (j < nums.size() - 1) {
                    if (nums[j] % 2 == nums[j + 1] % 2 && nums[j] <= threshold) {
                        ++curr_len;
                    }
                    if (nums[j] % 2 != nums[j + 1] % 2 && nums[j] <= threshold) {
                        ++curr_len;
                    } else {
                        break;
                    }
                }
            }
            if (curr_len > max_length) {
                max_length = curr_len;
            }
        }
        return max_length;
    }
};

int main() {
    // nums = [3,2,5,4], threshold = 5
    Solution s0;
    vector<int> nums0 = {3, 2, 5, 4};
    int threshold0 = 5;
    cout << s0.longestAlternatingSubarray(nums0, threshold0) << endl;

    // nums = [1,2], threshold = 2
    Solution s1;
    vector<int> nums1 = {1, 2};
    int threshold1 = 2;
    cout << s1.longestAlternatingSubarray(nums1, threshold1) << endl;

    // nums = [2,3,4,5], threshold = 4
    Solution s2;
    vector<int> nums2 = {2, 3, 4, 5};
    int threshold2 = 4;
    cout << s2.longestAlternatingSubarray(nums2, threshold2) << endl;

    // nums = [2], threshold = 2
    Solution s3;
    vector<int> nums3 = {2};
    int threshold3 = 2;
    cout << s3.longestAlternatingSubarray(nums3, threshold3) << endl;

    // nums = [2,2], threshold = 18
    Solution s4;
    vector<int> nums4 = {2, 2};
    int threshold4 = 18;
    cout << s4.longestAlternatingSubarray(nums4, threshold4) << endl;

    // nums = [2,8], threshold = 4
    Solution s5;
    vector<int> nums5 = {2, 8};
    int threshold5 = 4;
    cout << s5.longestAlternatingSubarray(nums5, threshold5) << endl;
    return 0;
}
