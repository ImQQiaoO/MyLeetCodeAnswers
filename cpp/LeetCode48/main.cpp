#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        auto msz = matrix.size();
        // 1. 首先将矩阵沿其纵向的中心轴对称进行反转
        for (size_t i = 0; i < msz / 2; ++i) {
            for (size_t j = 0; j < msz; ++j) {
                swap(matrix[j][i], matrix[j][msz - i - 1]);
            }
        }
        // 2. 再将矩阵沿右上=>左下方向进行轴对称翻转
        for (size_t i = 0; i < msz - 1; ++i) {
            for (size_t j = 0; j < msz - i - 1; ++j) {
                swap(matrix[i][j], matrix[msz - 1 - j][msz - 1 - i]);
            }
        }
    }
};

int main() {
    // matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Solution s0;
    vector<vector<int>> matrix0 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s0.rotate(matrix0);
    for (auto &row: matrix0) {
        for (auto &col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;

    // matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    Solution s1;
    vector<vector<int>> matrix1 = {{5, 1, 9, 11},
                                   {2, 4, 8, 10},
                                   {13, 3, 6, 7},
                                   {15, 14, 12, 16}};
    s1.rotate(matrix1);
    for (auto &row: matrix1) {
        for (auto &col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
