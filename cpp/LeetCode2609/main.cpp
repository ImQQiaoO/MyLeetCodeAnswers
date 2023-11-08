#include <iostream>

using namespace std;

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        // 滑动窗口
        int res = 0;
//        int l_sentinel = 0;
        int r_sentinel = 0;
        int num_one = 0;
        int num_zero = 0;
        while (r_sentinel < s.length()) {
            if (s[r_sentinel] == '0') {
                ++num_zero;
                ++r_sentinel;
            }
            while (r_sentinel < s.length() && s[r_sentinel] == '1') {
                ++r_sentinel;
                ++num_one;
                res = max(res, 2 * min(num_one, num_zero));
                if (s[r_sentinel] == '0') {
                    num_zero = 0;
                    num_one = 0;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s0;
    // s = "01000111"
    string s0_0 = "01000111";
    cout << s0.findTheLongestBalancedSubstring(s0_0) << endl;

    Solution s1;
    // s = "00111"
    string s1_0 = "00111";
    cout << s1.findTheLongestBalancedSubstring(s1_0) << endl;

    Solution s2;
    // s = "111"
    string s2_0 = "111";
    cout << s2.findTheLongestBalancedSubstring(s2_0) << endl;
    return 0;
}
