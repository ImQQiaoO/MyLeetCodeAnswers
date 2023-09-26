#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(vector<int> &res) {
    for (auto i: res) {
        cout << i << " ";
    }
    cout << endl;
}


class Solution {
public:
    vector<int> findDuplicates0(vector<int> &nums) {    // 超时
        sort(nums.begin(), nums.end());
//        cout << "curr vec is :";
//        print_vec(nums);
        auto iter = nums.begin() + 1;
        auto tail = nums.end();
        while (iter != tail) {
            if (*iter == *(iter - 1)) {
                swap(*iter, *(tail - 1));
//                cout << "after swap vec is :";
//                print_vec(nums);
                tail--;
                sort(nums.begin(), tail);
            } else {
                iter++;
            }
        }
        nums.erase(nums.begin(), tail);
        return nums;
    }

    vector<int> findDuplicates(vector<int> &nums) {    // 超时
        sort(nums.begin(), nums.end());
        auto iter = nums.begin() + 1;
        auto tail = nums.end();
        vector<int> res;
        while (iter != tail) {
            if (*iter == *(iter - 1)) {
                res.push_back(*iter);
            }
            iter++;
        }
        return res;
    }
};


int main() {
    // nums = [4,3,2,7,8,2,3,1]
    // Output: [2,3]
    Solution s0;
    vector<int> nums0 = {4, 3, 2, 7, 8, 2, 3, 1};
    auto res = s0.findDuplicates(nums0);
    print_vec(res);

    // nums = [1,1,2]
    // Output: [1]
    Solution s1;
    vector<int> nums1 = {1, 1, 2};
    auto res1 = s1.findDuplicates(nums1);
    print_vec(res1);

    // nums = [1]
    // Output: []
    Solution s2;
    vector<int> nums2 = {1};
    auto res2 = s2.findDuplicates(nums2);
    print_vec(res2);

    // [10,2,5,10,9,1,1,4,3,7]
    Solution s3;
    vector<int> nums3 = {10, 2, 5, 10, 9, 1, 1, 4, 3, 7};
    auto res3 = s3.findDuplicates(nums3);
    print_vec(res3);

    return 0;
}
