#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        // 考虑特殊情况，如果花坛长度为0：
        if (flowerbed.empty()) {
            return n == 0;
        }
        // 考虑特殊情况，如果花坛长度为1：
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0) {
                return n <= 1;
            } else {
                return n == 0;
            }
        }
        // 首先，找到首位是否为0，如果是0，找到有几个连续的0
        auto front_iter = flowerbed.begin();
        int cnt_head = 0;
        int res = 0;
        if (*front_iter == 0) {
            for (; front_iter != flowerbed.end() && *front_iter == 0; ++front_iter) {
                ++cnt_head;
            }
        }
        // 如果这个数组只有0，没有1
        if (flowerbed.size() == cnt_head) {
            return (cnt_head + 1) / 2 >= n;
        }
        res += cnt_head / 2;
//        cout << "res After front_iter: " << res << endl;
        // 接着，找到尾位是否为0，如果是0，找到有几个连续的0
        auto back_iter = flowerbed.end() - 1;
        int cnt_tail = 0;
        if (*back_iter == 0) {
            for (; back_iter != flowerbed.begin() && *back_iter == 0 && back_iter + 1 != front_iter;
                   --back_iter) {
                ++cnt_tail;
//                cout << "后检查已经执行" << endl;
            }
        }
        res += cnt_tail / 2;
//        cout << "res After back_iter: " << res << endl;
        // 继续找中间位置的连续的0
        int cnt = 0;
        for (; front_iter != back_iter + 1 && front_iter != flowerbed.end(); ++front_iter) {
//            cout << "curr element is: " << *front_iter << endl;
            if (*front_iter == 0) {
                ++cnt;
            } else {
//                cout << "cnt is: " << cnt << endl;
                res += (cnt - 1) / 2;
//                cout << "curr res is " << res << endl;
                cnt = 0;
            }
        }
//        cout << "res After middle_iter: " << res << endl;
        return res >= n;
    }
};

int main() {
    Solution s0;
    vector<int> nums0 = {1, 0, 0, 0, 1};
    cout << s0.canPlaceFlowers(nums0, 1) << endl;

    Solution s1;
    vector<int> nums1 = {0};
    cout << s1.canPlaceFlowers(nums1, 1) << endl;


    Solution s2;
    vector<int> nums2 = {0, 0};
    cout << s2.canPlaceFlowers(nums2, 2) << endl;

    Solution s3;
    vector<int> nums3 = {0, 0, 0, 0};
    cout << s3.canPlaceFlowers(nums3, 3) << endl;

    Solution s4;
    vector<int> nums4 = {0, 0, 0};
    cout << s4.canPlaceFlowers(nums4, 2) << endl;
    return 0;
}
