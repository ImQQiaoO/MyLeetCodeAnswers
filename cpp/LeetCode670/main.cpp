#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string target = to_string(num);
//        ranges::sort(target, [](const char &a, const char &b) {
//            return a > b;
//        });		// target是有序的（从大到小）
        sort(target.begin(), target.end(), [](const char &a, const char &b) {
            return a > b;
        });
        if (target == to_string(num)) {
            return num;
        } else {
            string temp_curr = to_string(num);
            string::iterator first_diff_it;
            for (size_t i = 0; i < target.size(); ++i) {
                if (target[i] != temp_curr[i]) {
                    // 找到第一个不同的位置
                    first_diff_it = temp_curr.begin() + i;
                    break;
                }
            }
            // 下面的是错误的，是和剩下的字符串中第一个最大的值的位置进行交换（多个相同的最大值时，交换第一个最大值）
            //const auto max_it = max_element(first_diff_it, temp_curr.end());
            // 出现多个最大值时，交换最后一个最大值
            auto max_it = max_element(first_diff_it, temp_curr.end());
            for (auto it = max_it + 1; it != temp_curr.end(); ++it) {
                if (*it == *max_it) {
                    max_it = it;
                }
            }
            swap(*first_diff_it, *max_it);
            return stoi(temp_curr);
        }
    }
};

int main() {
    Solution s0;
    cout << s0.maximumSwap(2736) << endl;

    Solution s1;
    cout << s1.maximumSwap(9973) << endl;

    Solution s2;
    cout << s2.maximumSwap(98368) << endl;

    Solution s4;
    cout << s4.maximumSwap(1993) << endl;
    return 0;
}
