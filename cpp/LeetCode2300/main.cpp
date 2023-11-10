#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 暴力解法时间复杂度O(n²), 超时
    //    vector<int> successfulPairs1(vector<int> &spells, vector<int> &potions, long long success) {
    //        vector<int> res_vec = {};
    //        for (int i = 0; i < spells.size(); i++) {
    //            int curr_res = 0;
    //            for (int j = 0; j < potions.size(); j++) {
    //                if (static_cast<long long>(spells[i]) * static_cast<long long>(potions[j]) >= success) {
    //                    curr_res++;
    //                }
    //            }
    //            res_vec.push_back(curr_res);
    //        }
    //        return res_vec;
    //    }
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        vector<int> res_vec = {};
        // 排序potions
        sort(potions.begin(), potions.end());
        for (size_t i = 0; i < spells.size(); ++i) {
            if (1LL * spells[i] * potions.back() < success) {
                res_vec.push_back(0);
                continue;
            }
//            for (size_t j = 0; j < potions.size(); ++j) {
//                if (1LL * spells[i] * potions[j] >= success) {
//                    res_vec.push_back(potions.size() - j);
//                    break;
//                }
////                if (j == potions.size() - 1) {
////                    res_vec.push_back(0);
////                }
//            }
            // 二分查找
            int left = 0, right = potions.size() - 1;
            while (left < right) {
                int mid = (right + left) / 2;
                if (1LL * spells[i] * potions[mid] >= success) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            res_vec.push_back(potions.size() - left);
        }
        return res_vec;
    }
};

int main() {
    // spells = [5,1,3], potions = [1,2,3,4,5], success = 7
    Solution solution0;
    vector<int> spells0 = {5, 1, 3};
    vector<int> potions0 = {1, 2, 3, 4, 5};
    long long success0 = 7;
    vector<int> res0 = solution0.successfulPairs(spells0, potions0, success0);
    for (int i = 0; i < res0.size(); i++) {
        cout << res0[i] << " ";
    }
    cout << endl;

    // spells = [3,1,2], potions = [8,5,8], success = 16
    Solution solution1;
    vector<int> spells1 = {3, 1, 2};
    vector<int> potions1 = {8, 5, 8};
    long long success1 = 16;
    vector<int> res1 = solution1.successfulPairs(spells1, potions1, success1);
    for (int i = 0; i < res1.size(); i++) {
        cout << res1[i] << " ";
    }
    cout << endl;
    return 0;
}
