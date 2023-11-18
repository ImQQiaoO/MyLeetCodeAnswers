#include <iostream>

using namespace std;

class Solution {
public:
    static int accountBalanceAfterPurchase(int purchaseAmount) {
        return 100 - (purchaseAmount + 5) / 10 * 10;    // 将话费的钱进行四舍五入
    }
};

int main() {
    std::cout << Solution::accountBalanceAfterPurchase(9) << std::endl;
    std::cout << Solution::accountBalanceAfterPurchase(15) << std::endl;
    return 0;
}
