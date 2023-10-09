#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int splitNum(int num) {
        // 1. 计算数字的位数
        string numStr = to_string(num);
        sort(numStr.begin(), numStr.end());
        string split_num0;
        string split_num1;
        for (std::string::size_type i = 0; i != numStr.size(); ++i) {
            if (i % 2 == 0) {
                split_num0 += numStr[i];
            } else {
                split_num1 += numStr[i];
            }
        }
        return stoi(split_num0) + stoi(split_num1);
    }
};

int main() {
    Solution s0;
    cout << s0.splitNum(4325) << endl;

    Solution s1;
    cout << s1.splitNum(687) << endl;

}
