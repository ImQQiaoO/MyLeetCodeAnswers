#include <algorithm>
#include <iostream>
#include <vector>

/* LeetCode 56 */

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) {return a[0] < b[0];});
        vector<vector<int>> res;
        int left_sentinel = intervals[0][0], right_sentinel = intervals[0][1];
        for (vector<vector<int>>::size_type i = 0; i < intervals.size(); ++i) {
            if (i + 1 < intervals.size() && intervals[i + 1][0] <= right_sentinel) {
                right_sentinel = max(intervals[i + 1][1], right_sentinel);
            } else {
                res.push_back({left_sentinel, right_sentinel});
                if (i + 1 < intervals.size()) {
                    left_sentinel = intervals[i + 1][0];
                    right_sentinel = intervals[i + 1][1];
                }
            }
        }
        return res;
    }
};

void print_vec(vector<vector<int>> &res);

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> intervals1 = {{1, 4}};
    vector<vector<int>> intervals2 = {{1, 4}, {2, 3}};
    vector<vector<int>> res = s.merge(intervals);
    vector<vector<int>> res1 = s.merge(intervals1);
    vector<vector<int>> res2 = s.merge(intervals2);
    print_vec(res);
    cout << endl;
    print_vec(res1);
    cout << endl;
    print_vec(res2);

    return 0;
}

void print_vec(vector<vector<int>> &res) {
    for (const auto &i: res) {
        for (const auto &j: i) {
            cout << j << " ";
        }
        cout << ", " ;
    }
}
