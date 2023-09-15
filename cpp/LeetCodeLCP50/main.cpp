#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (auto & operation : operations) {
            int move_num = gem[operation[0]] / 2;
            gem[operation[0]] -= move_num;
            gem[operation[1]] += move_num;
        }
        int max_val = *max_element(gem.begin(), gem.end());
        int min_val = *min_element(gem.begin(), gem.end());
        return max_val - min_val;
    }
};

int main() {
    // gem = [3,1,2], operations = [[0,2],[2,1],[2,0]]
    vector<int> gem{3, 1, 2};
    vector<vector<int>> operations{{0, 2}, {2, 1}, {2, 0}};
    Solution solution;
    cout << solution.giveGem(gem, operations) << endl;


    // gem = [100,0,50,100], operations = [[0,2],[0,1],[3,0],[3,0]]
    vector<int> gem2{100, 0, 50, 100};
    vector<vector<int>> operations2{{0, 2}, {0, 1}, {3, 0}, {3, 0}};
    cout << solution.giveGem(gem2, operations2) << endl;


    // gem = [0,0,0,0], operations = [[1,2],[3,1],[1,2]]
    vector<int> gem3{0, 0, 0, 0};
    vector<vector<int>> operations3{{1, 2}, {3, 1}, {1, 2}};
    cout << solution.giveGem(gem3, operations3) << endl;
    return 0;
}
