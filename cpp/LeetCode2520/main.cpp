#include <iostream>

using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        string str = to_string(num);
        for (size_t i = 0; i != str.size(); ++i) {
            if (num % (str[i] - '0') == 0) {
                ++res;
            }
        }
        return res;
    }
};

int main() {
    Solution s1;
    cout << s1.countDigits(7) << endl;
    Solution s2;
    cout << s2.countDigits(121) << endl;
    Solution s3;
    cout << s3.countDigits(1248) << endl;
    return 0;
}
