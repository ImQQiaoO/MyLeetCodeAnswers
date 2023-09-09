#include <algorithm>
#include <iostream>
#include <vector>

/* LeetCode 57 */

using namespace std;

class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
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
    // 插入区间
    vector<vector<int>> intervals = {{1, 3},
                                     {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> res = s.insert(intervals, newInterval);
    print_vec(res);
    cout << endl;

    return 0;
}

void print_vec(vector<vector<int>> &res) {
    for (const auto &i: res) {
        for (const auto &j: i) {
            cout << j << " ";
        }
        cout << ", ";
    }
}
