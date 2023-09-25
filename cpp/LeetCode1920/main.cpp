#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = nums[nums[i]];
        }
        return res;
    }
};

void print_res(vector<int> &res);

int main() {
    // nums = [0,2,1,5,3,4]
    Solution s0;
    vector<int> nums0 = {0, 2, 1, 5, 3, 4};
    vector<int> res0 = s0.buildArray(nums0);
    print_res(res0);

    // nums = [5,0,1,2,3,4]
    Solution s1;
    vector<int> nums1 = {5, 0, 1, 2, 3, 4};
    vector<int> res1 = s1.buildArray(nums1);
    print_res(res1);

    return 0;
}

void print_res(vector<int> &res) {
    for (auto &i : res) {
        cout << i << " ";
    }
    cout << endl;
}
