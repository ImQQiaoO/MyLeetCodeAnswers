#include <iostream>

using namespace std;

class Solution {
public:
    int distMoney(int money, int children) {
        int given_children = 0; // 已经给了几个孩子8元
        if (money < children) {     // 如果钱根本不够给任何一个孩子8元，直接返回-1
            return -1;
        }
        bool allocated = false;
        // 如果剩余的钱不足8或者除了最后一个孩子，其他孩子都有了8元
        while (money >= 7 + (children - given_children) && given_children < children - 1) {
            money -= 8;
            given_children++;
            allocated = true;
        }

        if (money == 4 && allocated && given_children == children - 1) {
            given_children--;
        }
        if (money == 8 && allocated && given_children == children - 1) {
            given_children++;
        }
        return given_children;
    }
};

int main() {
    // money = 20, children = 3
    Solution s0;
    cout << s0.distMoney(20, 3) << endl;

    // money = 16, children = 2
    Solution s1;
    cout << s1.distMoney(16, 2) << endl;

    // money = 2, children = 2
    Solution s2;
    cout << s2.distMoney(2, 2) << endl;

    Solution s3;
    cout << s3.distMoney(17, 2) << endl;

    return 0;
}
