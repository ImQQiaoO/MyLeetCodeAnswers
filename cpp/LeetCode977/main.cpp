#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            nums[i] = nums[i] * nums[i];
        }
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    Solution solution;
    vector<int> res = solution.sortedSquares(nums);
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }

    return 0;
}
