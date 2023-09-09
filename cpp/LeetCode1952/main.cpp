#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isThree(int n) {       // n >= 1
        int sqrt_n = static_cast<int>(sqrt(n));
        if (sqrt_n * sqrt_n != n || n == 1) {
            return false;
        } else {
            for (int i = 2; i <= sqrt_n; ++i) {
                if (n % i == 0 && i != sqrt_n) {
                    return false;
                }
            }
        }
        return true;
    }
};


int main() {
    Solution s;
    cout << s.isThree(3) << endl;
    cout << s.isThree(2) << endl;
    cout << s.isThree(4) << endl;
    cout << s.isThree(25) << endl;
    return 0;
}
