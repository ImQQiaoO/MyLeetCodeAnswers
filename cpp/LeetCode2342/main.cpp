#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;
/**
 * 思路：
 * 1. 遍历nums，记录下每个数位对应的数组元素列表
 *    例如： mp[9]=[18,27,36]
 * 2. 遍历map，对于每个数位和，取其对应的两个最大元素之和，再与记录比较即可。
 *    例如，对于数位和 999 而言，mp[9]=[18,27,36]mp[9] = [18, 27, 36]mp[9]=[18,27,36]，
 *    取最大的两个元素 [27,36][27, 36][27,36] 之和。
 */
class Solution {
    int get_sum(int num) {
        int res = 0;
        while (num > 0) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }

public:
    int maximumSum(vector<int> &nums) {
        int res = -1;
        map<int, priority_queue<int>> mp;
        // 遍历数组
        for (int num : nums) {
            mp[get_sum(num)].push(num); // 优先级队列存放操作的时间复杂度为O(log n)
        }
        // 遍历map
        for (auto &i_pq : mp) {
            if (i_pq.second.size() >= 2) {
                int first_max = i_pq.second.top();
                i_pq.second.pop();
                int second_max = i_pq.second.top();
                res = max(res, first_max + second_max);
            } 
        }
        return res;
    }
};

int main() {
    // nums = [18,43,36,13,7]
    Solution s0;
    vector<int> nums0 = {18, 43, 36, 13, 7};
    cout << s0.maximumSum(nums0) << endl;

    // nums = [10,12,19,14]
    Solution s1;
    vector<int> nums1 = {10, 12, 19, 14};
    cout << s1.maximumSum(nums1) << endl;

    return 0;
}
