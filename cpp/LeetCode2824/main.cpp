#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPairs(vector<int> &nums, int target) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                ans += (nums[i] + nums[j] < target);
            }
        }
        return ans;
    }
};


int main() {
    //nums = [-1,1,2,3,1], target = 2
    Solution s;
    vector<int> nums = {-1, 1, 2, 3, 1};
    int target = 2;
    cout << s.countPairs(nums, target) << endl;

    return 0;
}
