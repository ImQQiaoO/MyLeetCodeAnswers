#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {        // 动态规划
        if (n <= 1) return n;;
        int fib_vec[2] = {1, 1};
        for (int i = 2; i < n; ++i) {
            int temp = fib_vec[0] + fib_vec[1];
            fib_vec[0] = fib_vec[1];
            fib_vec[1] = temp;
        }
        return fib_vec[1];
    }

    int fib1(int n) {       // 递归
        if (n <= 1) return n;
        return fib1(n - 1) + fib1(n - 2);
    }
};

int main() {
    Solution s;
    cout << s.fib(4) << endl;
    cout << s.fib1(4) << endl;
    return 0;
}
