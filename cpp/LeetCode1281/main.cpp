#include <iostream>
#include <string>

/**
 * 2023/08/09
 */
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        auto num_str = to_string(n);
        auto digit = num_str.size();
        int product = 1;
        int sum = 0;
        for (decltype(digit) i = 0; i != digit; ++i) {
            int temp =  num_str[i] - '0';
            product *= temp;
            sum += temp;
        }
        return product - sum;
    }
};

int main() {
    Solution s;
    cout << s.subtractProductAndSum(234) << endl;
    cout << s.subtractProductAndSum(4421) << endl;
    return 0;
}
