#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        // 三指针法，要求时间复杂度为O(n)，空间复杂度为O(1)
        int l = 0, r = nums.size() - 1, curr = 0;
        const int target = 1;//在本题中，target设为1
        while (curr <= r) {
            if (nums[curr] > target) {
                std::swap(nums[curr], nums[r]);
                --r;
            } else if (nums[curr] < target) {
                std::swap(nums[curr], nums[l]);
                ++l;
                ++curr;
            } else if (nums[curr] == target) {
                ++curr;
            }
        }
    }
};

int main() {
    Solution sol0;
    vector<int> nums0 = {2, 0, 2, 1, 1, 0};
    sol0.sortColors(nums0);
    for (int i = 0; i < nums0.size(); i++) {
        cout << nums0[i] << " ";
    }
    cout << endl;

    Solution sol1;
    vector<int> nums1 = {2, 0, 1};
    sol1.sortColors(nums1);
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
