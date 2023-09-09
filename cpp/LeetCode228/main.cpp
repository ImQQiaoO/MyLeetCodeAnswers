#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        int continuous_cnt = 0;
        vector<string> res;
        for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
            if (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
                continuous_cnt++;
            } else {
                if (continuous_cnt == 0) {
                    res.push_back(to_string(nums[i]));
                } else {
                    string continuous_log = to_string(nums[i - continuous_cnt]) + "->"
                            + to_string(nums[i]);
                    res.push_back(continuous_log);
                }
                continuous_cnt = 0;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
//    vector<int> nums{0, 1, 2, 4, 5, 7};
//    vector<int> nums{0, 2, 3, 4, 6, 8, 9};
//    vector<int> nums{0};
//    vector<int> nums{0, 1, 2, 4, 5, 7};
    vector<int> nums{-1};
    vector<string> res = s.summaryRanges(nums);
    for (const auto &r: res) {
        cout << r << endl;
    }
    return 0;
}
