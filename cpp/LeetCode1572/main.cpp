#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>> &mat) {
        int sumDown = 0, sumUp = 0, n = mat.size(), mid = n /2;
        for (int i = 0; i < n; ++i) {
            sumDown += mat[i][i];
            sumUp += mat[n - 1 - i][i];
        }
//        cout << sumDown << endl;
//        cout << sumUp << endl;

//        if (mat.size() % 2 == 0) {
//            return sumUp + sumDown;
//        } else {
//            return sumUp + sumDown - mat[mat.size() / 2][mat.size() / 2];
//        }
        return sumUp + sumDown - mat[mid][mid] * (n & 1);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};
    vector<vector<int>> mat2 = {{1, 1, 1, 1},
                                {1, 1, 1, 1},
                                {1, 1, 1, 1},
                                {1, 1, 1, 1}};
    vector<vector<int>> mat3 = {{5}};
    cout << solution.diagonalSum(mat) << endl;
    cout << solution.diagonalSum(mat2) << endl;
    cout << solution.diagonalSum(mat3) << endl;
    return 0;
}
