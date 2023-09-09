#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(const vector<int> &nums, int target) {
    auto begin = nums.begin(), end = nums.end();
    while (true) {
        if (begin == end) {
            return -1;
        }
        auto mid = begin + (end - begin) / 2;
        if (target < *mid) {
            end = mid;
        } else if (target > *mid) {
            begin = mid + 1;
        } else {
            return mid - nums.begin();
        }
    }
}

class Solution {
    friend int binary_search(const vector<int> &nums, int target);

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        for (auto &row: matrix) {
            if (binary_search(row, target) != -1) {
                return true;
            }
        }
        return false;
    }
};


int main() {
    vector<vector<int>> matrix = {{1,  3,  5,  7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 50}};
    int target = 3;
    Solution s;
    cout << s.searchMatrix(matrix, target) << endl;
    return 0;
}
