#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int sz = nums.size();
        // 对k取余
        k = k % sz;
        // k == 0
        if (k == 0) {
            return;
        }
        // 移动数组
        for (int i = 0; i < sz - k; ++i) {
            nums.push_back(nums[i]);
        }
        nums.erase(nums.begin(), nums.begin() + sz - k);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(nums, 3);
    for (auto num: nums) {
        cout << num << " ";
    }
    cout << endl;

    Solution s1;
    vector<int> nums1 = {-1, -100, 3, 99};
    s1.rotate(nums1, 2);
    for (auto num: nums1) {
        cout << num << " ";
    }
    return 0;
}
