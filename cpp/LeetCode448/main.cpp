#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> res;
        int curr = 1;
        int i = 0;
        int length = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        auto iter = unique(nums.begin(), nums.end());
        nums.erase(iter, nums.end());
        while (curr != length + 1) {
            if (curr == nums[i]) {
                i++;
            } else {
                res.push_back(curr);
            }
            curr++;
        }
        return res;
    }
};

void print(vector<int> &result);

int main() {
    Solution solution;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = solution.findDisappearedNumbers(nums);
    vector<int> nums2 = {1, 1};
//    nums2 = {2, 2, 3, 4, 5};
    vector<int> result2 = solution.findDisappearedNumbers(nums2);
    print(result);
    print(result2);
    return 0;
}

void print(vector<int> &result) {
    for (const auto &num: result) {
        cout << num << " ";
    }
    cout << endl;
}
