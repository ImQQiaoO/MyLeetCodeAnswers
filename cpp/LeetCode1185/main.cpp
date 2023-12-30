#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
tm 结构体
在 tm 结构体中，各个成员的意义如下：

tm_year：表示年份，自 1900 年起的年数。比如，year - 1900 表示的是从 1900 年到 year 年的年数。
tm_mon：表示月份，从 0 开始计数到 11。因此，month - 1 是将 1-12 的月份转换为 0-11 的范围。
tm_mday：表示一个月中的第几天，从 1 到 31。
tm_hour, tm_min, tm_sec：分别表示小时、分钟和秒。在您的代码中，这些都被初始化为 0。

mktime 函数
mktime 函数的作用是把 tm 结构体表示的本地时间转换为从标准纪元（即 1970 年 1 月 1 日 00:00:00 UTC）开始所经过的秒数。这个函数也会自动调整 tm 结构体的成员变量，以修正诸如月份或天数超出范围的情况。

此外，mktime 还会设置 tm_wday 和 tm_yday 这两个成员变量。其中：

tm_wday：表示星期几，从 0（星期日）到 6（星期六）。
tm_yday：表示这是一年中的第几天，从 0 开始。
 */
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector <string> week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        tm time = {0, 0, 0, day, month - 1, year - 1900};
        mktime(&time);
        return week[time.tm_wday];
    }
};


int main() {
    // day = 31, month = 8, year = 2019
    Solution s;
    cout << s.dayOfTheWeek(31, 8, 2019) << endl;

    // day = 18, month = 7, year = 1999
    Solution s1;
    cout << s1.dayOfTheWeek(18, 7, 1999) << endl;

    // day = 15, month = 8, year = 1993
    Solution s2;
    cout << s2.dayOfTheWeek(15, 8, 1993) << endl;

    return 0;
}
