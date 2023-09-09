#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2) {
        vector<int> same_num;
        bool is_repeat = false;
        int min_nums1;
        int min_nums2;
        for (int i: nums1) {
            // 首先判断两个数组中是否存在相同的元素，如果有，找到最小的相同的元素
            for (int j: nums2) {
                if (i == j) {
                    is_repeat = true;
                    same_num.push_back(i);
                }
            }
        }
        if (is_repeat) {
            return *min_element(same_num.begin(), same_num.end());
        }
        min_nums1 = *min_element(nums1.begin(), nums1.end());
        min_nums2 = *min_element(nums2.begin(), nums2.end());
        return min(min_nums1, min_nums2) * 10 + max(min_nums1, min_nums2);
    }
};

int main() {
    vector<int> num1 = {4, 1, 3};
    vector<int> num2 = {5, 7};
    Solution solution;
    cout << solution.minNumber(num1, num2) << endl;

    vector<int> num11 = {6, 4, 3, 7, 2, 1, 8, 5};
    vector<int> num21 = {6, 8, 5, 3, 1, 7, 4, 2};
    Solution solution1;
    cout << solution1.minNumber(num11, num21) << endl;

    vector<int> num12 = {7,5,6};
    vector<int> num22 = {1,4};
    Solution solution2;
    cout << solution1.minNumber(num12, num22) << endl;
    return 0;
}
