#include <iostream>

using namespace std;

/* LeetCode 2240 */

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {   
        long long res = 0;                                               // bad solution: 超时
        for (int i = 0; i <= total / cost1; ++i) {                       // i : 买钢笔的数量
            // for (int j = 0; j <= (total - (i * cost1)) / cost2; ++j) {   // j : 买铅笔的数量
            //     ++res;
            // }
            res = res + (total - i * cost1) / cost2 + 1;
        }
        return res;
    }
};

int main() {
    cout << Solution().waysToBuyPensPencils(20, 10, 5) << endl;
    cout << Solution().waysToBuyPensPencils(5, 10, 10) << endl;
    return 0;
}
