#include <iostream>

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 找出钟表上两个指针相对于12的角度
        double h = hour % 12 / 12.0 * 360 + minutes / 60.0 * 30;
        double m = minutes / 60.0 * 360;
        // 计算两个指针的夹角
        double angle = abs(h - m);
        return angle > 180 ? 360 - angle : angle;
    }
};

int main() {
    // hour = 12, minutes = 30
    Solution s0;
    int hour0 = 12, minutes0 = 30;
    cout << s0.angleClock(hour0, minutes0) << endl;

    // hour = 3, minutes = 30
    Solution s1;
    int hour1 = 3, minutes1 = 30;
    cout << s1.angleClock(hour1, minutes1) << endl;

    // hour = 3, minutes = 15
    Solution s2;
    int hour2 = 3, minutes2 = 15;
    cout << s2.angleClock(hour2, minutes2) << endl;

    // hour = 4, minutes = 50
    Solution s3;
    int hour3 = 4, minutes3 = 50;
    cout << s3.angleClock(hour3, minutes3) << endl;

    // hour = 12, minutes = 0
    Solution s4;
    int hour4 = 12, minutes4 = 0;
    cout << s4.angleClock(hour4, minutes4) << endl;
    return 0;
}
