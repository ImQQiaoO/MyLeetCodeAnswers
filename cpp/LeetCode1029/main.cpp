#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/* LeetCode 1029 */

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        vector<int> difference(costs.size());
        int res = 0;
        // 假设所有员工都去B点
        for (int i = 0; i < costs.size(); ++i) {
            res += costs[i][1];
            difference[i] = costs[i][0] - costs[i][1];
        }
        // 找出从B点转移到A点的成本最低的 costs / 2 个人
        sort(difference.begin(), difference.end());
//        for (int i = 0; i < costs.size(); ++i) {
//            cout << difference[i] << endl;
//        }
//        cout << "---------------------" << endl;
        for (int i = 0; i < costs.size() / 2; ++i) {
            res += difference[i];
        }
        return res;
    }
};

int main() {
    // costs = [[10,20],[30,200],[400,50],[30,20]]
    Solution s;
    vector<vector<int>> costs1 = {{10,  20},
                                  {30,  200},
                                  {400, 50},
                                  {30,  20}};
    cout << s.twoCitySchedCost(costs1) << endl;


    // costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
    Solution s2;
    vector<vector<int>> costs2 = {{259, 770},
                                  {448, 54},
                                  {926, 667},
                                  {184, 139},
                                  {840, 118},
                                  {577, 469}};
    cout << s2.twoCitySchedCost(costs2) << endl;

    // costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
    Solution s3;
    vector<vector<int>> costs3 = {{515, 563},
                                  {451, 713},
                                  {537, 709},
                                  {343, 819},
                                  {855, 779},
                                  {457, 60},
                                  {650, 359},
                                  {631, 42}};
    cout << s3.twoCitySchedCost(costs3) << endl;

    return 0;
}
