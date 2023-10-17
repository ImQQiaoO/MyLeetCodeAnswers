#include <iostream>

using namespace std;

class Solution {
public:
    int sumOfMultiples(int n) {
int sum = 0;
        for (int i = 0; i <= n; ++i) {
            if (i % 3 == 0) {
                sum += i;
            } else if (i % 5 == 0) {
                sum += i;
            } else if (i % 7 == 0) {
                sum += i;
            }
        }
        return sum;
    }
};

int main() {
    Solution s0;
    cout << s0.sumOfMultiples(7) << endl;

    Solution s1;
    cout << s1.sumOfMultiples(10) << endl;

    Solution s2;
    cout << s2.sumOfMultiples(9) << endl;
    return 0;
}
