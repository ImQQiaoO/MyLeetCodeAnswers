#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 3) {
            if (i + 1 == nums.size() || nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        return 0;
    }
};

int main() {
    Solution s0;
    vector<int> nums0{2, 2, 3, 2};
    cout << s0.singleNumber(nums0) << endl;

    // nums = [0,1,0,1,0,1,99]
    Solution s1;
    vector<int> nums1{0, 1, 0, 1, 0, 1, 99};
    cout << s1.singleNumber(nums1) << endl;
    return 0;
}
