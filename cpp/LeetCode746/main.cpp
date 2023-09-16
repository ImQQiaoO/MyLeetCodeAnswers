#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**  
     * 这道题是先跳，跳完了之后再支付
     */
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> costed_dp(cost.size() + 1);
        costed_dp[0] = 0;
        costed_dp[1] = 0;       // 默认情况下第一步无论调到哪里都不需要花钱
        for (int i = 2; i < cost.size() + 1; ++i) {
            costed_dp[i] = min(costed_dp[i - 1] + cost[i - 1], 
                costed_dp[i - 2] + cost[i - 2]);
        }
        return costed_dp[cost.size()];
    }
};

int main() {
    // cost = [10,15,20]
    Solution s;
    vector<int> cost = {10, 15, 20};
    cout << s.minCostClimbingStairs(cost) << endl;

    // cost = [1,100,1,1,1,100,1,1,100,1]
    Solution s1;
    vector<int> cost1 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << s1.minCostClimbingStairs(cost1) << endl;

    return 0;
}
