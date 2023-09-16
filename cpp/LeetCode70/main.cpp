#include <iostream>
#include <vector>

using namespace std;

/*
 * 动态规划五部曲：
 * 1. 确定dp数组（dp table）以及下标的含义
 * 2. 确定递推公式
 * 3. dp数组如何初始化
 * 4. 确定遍历顺序
 * 5. 举例推导dp数组
 */

class Solution {
public:
    int climbStairs(int n) {    // n是台阶数， 动态规划
        if (n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;          // 上一节台阶只有一种方法
        dp[2] = 2;          // 上两节台阶有两种方法
        for (int i = 3; i <= n; i++) {// 注意i是从3开始的
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution s1;
    cout << s1.climbStairs(3) << endl;
    return 0;
}
