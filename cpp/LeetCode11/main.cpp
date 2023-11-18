#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 双指针法
     * @param height
     * @return
     */
    int maxArea(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while (left < right) {
            res = max((min(height[left], height[right]) * (right - left)), res);
            if (height[left] < height[right]) ++left;
            else --right;
        }
        return res;
    }

    /**
     * 暴力法  ---------- 超时 ----------
     * @param height
     * @return
     */
    int maxArea1(vector<int> &height) {
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                res = max((min(height[i], height[j]) * (j - i)), res);
            }
        }
        return res;
    }
};

int main() {
    // [1,8,6,2,5,4,8,3,7]
    Solution s0;
    vector<int> height0 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s0.maxArea(height0) << endl;

    // [1,1]
    Solution s1;
    vector<int> height1 = {1, 1};
    cout << s1.maxArea(height1) << endl;
    return 0;
}
