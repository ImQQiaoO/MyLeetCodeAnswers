#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximizeSum(vector<int> &nums, int k) {
        return (*max_element(nums.begin(), nums.end()) + (*max_element(nums.begin(), nums.end()) + k - 1)) * k / 2;
    }
};

int main() {
    // nums = [1,2,3,4,5], k = 3
    Solution s0;
    vector<int> nums0 = {1, 2, 3, 4, 5};
    int k0 = 3;
    cout << s0.maximizeSum(nums0, k0) << endl;

    // nums = [5,5,5], k = 2
    Solution s1;
    vector<int> nums1 = {5, 5, 5};
    int k1 = 2;
    cout << s1.maximizeSum(nums1, k1) << endl;
    return 0;
}
