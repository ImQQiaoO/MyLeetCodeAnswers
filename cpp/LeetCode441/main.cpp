#include <iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int reduce = 1;
        while (n > reduce) {
            n -= reduce;
            reduce++;
        }
        if (n != reduce) {
            reduce--;
        }
        return reduce;
    }
};

int main() {

    Solution s;
    cout << s.arrangeCoins(5) << endl;
    cout << s.arrangeCoins(8) << endl;
    cout << s.arrangeCoins(3) << endl;
    cout << s.arrangeCoins(1) << endl;


    return 0;
}