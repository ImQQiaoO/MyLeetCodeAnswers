#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
private:
    pair<int, int> last_position = {0, 0};
public:
    bool checkValidGrid(vector<vector<int>> &grid) {
        if (grid[0][0] != 0) {
            return false;
        }
        int sequence = 1;
        int n = static_cast<int>(grid.size());
        // find the position of the next number
        while (sequence < n * n) {
            bool found = false;
            for (int i = 0; i < n; ++i) {
                if (found) {
                    break;
                }
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == sequence) {
                        found = true;
                        if (!check_position({i, j})) {
                            return false;
                        }
                        sequence++;
                        break;
                    }
                }
            }
        }
        return true;
    }

    bool check_position(const pair<int, int> &curr_position) {
        // check the last position and current position
        vector<pair<int, int>> possible_positions = {{curr_position.first - 1, curr_position.second + 2},
                                                     {curr_position.first - 1, curr_position.second - 2},
                                                     {curr_position.first + 1, curr_position.second + 2},
                                                     {curr_position.first + 1, curr_position.second - 2},
                                                     {curr_position.first + 2, curr_position.second + 1},
                                                     {curr_position.first + 2, curr_position.second - 1},
                                                     {curr_position.first - 2, curr_position.second + 1},
                                                     {curr_position.first - 2, curr_position.second - 1}};
        return any_of(possible_positions.begin(), possible_positions.end(), [&](const pair<int, int> &position) {
            if (position == last_position) {
                last_position = curr_position;
                return true;
            }
            return false;
        });
    }
};

int main() {
    // grid = [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]
    Solution s;
    vector<vector<int>> grid = {{0,  11, 16, 5,  20},
                                {17, 4,  19, 10, 15},
                                {12, 1,  8,  21, 6},
                                {3,  18, 23, 14, 9},
                                {24, 13, 2,  7,  22}};
    bool result = s.checkValidGrid(grid);
    cout << result << endl;

    Solution s1;
    // grid = [[0,3,6],[5,8,1],[2,7,4]]
    vector<vector<int>> grid2 = {{0, 3, 6},
                                 {5, 8, 1},
                                 {2, 7, 4}};
    bool result2 = s1.checkValidGrid(grid2);
    cout << result2 << endl;
    return 0;
}
