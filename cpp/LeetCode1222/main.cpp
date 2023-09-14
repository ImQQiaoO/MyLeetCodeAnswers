#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king) {
        const int king_x = king[0];
        const int king_y = king[1];
        vector<vector<int>> res;
        // 首先查找king的右侧水平方向上有无符合条件的棋子
        for (int temp_king_y = king_y + 1; temp_king_y < 8; ++temp_king_y) {
            vector<int> curr_position{king_x, temp_king_y};
            if (search_queens(queens, curr_position)) {
                res.push_back(curr_position);
                break;
            }
        }
        // 查找king左侧水平方向上有无符合条件的棋子
        for (int temp_king_y = king_y - 1; temp_king_y >= 0; --temp_king_y) {
            vector<int> curr_position{king_x, temp_king_y};
            if (search_queens(queens, curr_position)) {
                res.push_back(curr_position);
                break;
            }
        }
        // 查找king上方竖直方向上有无符合条件的棋子
        for (int temp_king_x = king_x - 1; temp_king_x >= 0; --temp_king_x) {
            vector<int> curr_position{temp_king_x, king_y};
            if (search_queens(queens, curr_position)) {
                res.push_back(curr_position);
                break;
            }
        }
        // 查找king下方竖直方向上有无符合条件的棋子
        for (int temp_king_x = king_x + 1; temp_king_x < 8; ++temp_king_x) {
            vector<int> curr_position{temp_king_x, king_y};
            if (search_queens(queens, curr_position)) {
                res.push_back(curr_position);
                break;
            }
        }
        // 查找king右上方斜对角线方向上有无符合条件的棋子
        for (int temp_king_x = king_x - 1, temp_king_y = king_y + 1; temp_king_x >= 0 && temp_king_y < 8;
             --temp_king_x, ++temp_king_y) {
            vector<int> curr_position{temp_king_x, temp_king_y};
            if (search_queens(queens, curr_position)) {
                res.push_back(curr_position);
                break;
            }
        }
        // 查找king左上方斜对角线方向上有无符合条件的棋子
        for (int temp_king_x = king_x - 1, temp_king_y = king_y - 1; temp_king_x >= 0 && temp_king_y >= 0;
             --temp_king_x, --temp_king_y) {
            vector<int> curr_position{temp_king_x, temp_king_y};
            if (search_queens(queens, curr_position)) {
                res.push_back(curr_position);
                break;
            }
        }
        // 查找king右下方斜对角线方向上有无符合条件的棋子
        for (int temp_king_x = king_x + 1, temp_king_y = king_y + 1; temp_king_x < 8 && temp_king_y < 8;
             ++temp_king_x, ++temp_king_y) {
            vector<int> curr_position{temp_king_x, temp_king_y};
            if (search_queens(queens, curr_position)) {
                res.push_back(curr_position);
                break;
            }
        }
        // 查找king左下方斜对角线方向上有无符合条件的棋子
        for (int temp_king_x = king_x + 1, temp_king_y = king_y - 1; temp_king_x < 8 && temp_king_y >= 0;
             ++temp_king_x, --temp_king_y) {
            vector<int> curr_position{temp_king_x, temp_king_y};
            if (search_queens(queens, curr_position)) {
                res.push_back(curr_position);
                break;
            }
        }
        return res;
    }

    bool search_queens(const vector<vector<int>> &queen, const vector<int> &curr_position) {
        auto iter = find(queen.begin(), queen.end(), curr_position);
        return iter != queen.end();
    }
};

void print_res(vector<vector<int>> &result0) {
    for (const auto &row: result0) {
        for (const auto &col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

int main() {
    // queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
    Solution s0;
    vector<vector<int>> queens0 = {{0, 1},
                                   {1, 0},
                                   {4, 0},
                                   {0, 4},
                                   {3, 3},
                                   {2, 4}};
    vector<int> king0 = {0, 0};
    vector<vector<int>> result0 = s0.queensAttacktheKing(queens0, king0);
    print_res(result0);
    cout << "----------------------" << endl;

    // queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
    Solution s1;
    vector<vector<int>> queens1 = {{0, 0},
                                   {1, 1},
                                   {2, 2},
                                   {3, 4},
                                   {3, 5},
                                   {4, 4},
                                   {4, 5}};
    vector<int> king1 = {3, 3};
    vector<vector<int>> result1 = s1.queensAttacktheKing(queens1, king1);
    print_res(result1);
    cout << "----------------------" << endl;

    // queens = [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],[0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],[0,5],[4,2],[1,0],[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]], king = [3,4]
    Solution s2;
    vector<vector<int>> queens2 = {{5, 6},
                                   {7, 7},
                                   {2, 1},
                                   {0, 7},
                                   {1, 6},
                                   {5, 1},
                                   {3, 7},
                                   {0, 3},
                                   {4, 0},
                                   {1, 2},
                                   {6, 3},
                                   {5, 0},
                                   {0, 4},
                                   {2, 2},
                                   {1, 1},
                                   {6, 4},
                                   {5, 4},
                                   {0, 0},
                                   {2, 6},
                                   {4, 5},
                                   {5, 2},
                                   {1, 4},
                                   {7, 5},
                                   {2, 3},
                                   {0, 5},
                                   {4, 2},
                                   {1, 0},
                                   {2, 7},
                                   {0, 1},
                                   {4, 6},
                                   {6, 1},
                                   {0, 6},
                                   {4, 3},
                                   {1, 7}};
    vector<int> king2 = {3, 4};
    vector<vector<int>> result2 = s2.queensAttacktheKing(queens2, king2);
    print_res(result2);
    cout << "----------------------" << endl;

    return 0;
}
