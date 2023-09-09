#include <iostream>
#include <vector>
#include <algorithm>
#include <valarray>

using namespace std;

class Solution {
public:
    long long repairCars(vector<int> &ranks, int cars) {
        auto get_min_rank = (*min_element(ranks.begin(), ranks.end()));
        long long get_car_square = static_cast<long long>(cars) * static_cast<long long>(cars);
        long long time_max_limit = get_min_rank * get_car_square;
        long long time_min_limit = 0LL;
        while (time_min_limit < time_max_limit) {
            long long time_mid = time_min_limit + (time_max_limit - time_min_limit) / 2;
            long long total_car_num = 0;
            for (const auto &rank: ranks) {
                total_car_num += static_cast<long long>(sqrt(time_mid / rank));
            }
//在调整左右指针位置时有以下几点要注意：
//
//当中间元素小于目标值时，左指针需要移动到中间位置的右边一位，即 left = mid + 1。
// 这是因为我们已经检查了中间位置的元素，所以可以排除它。
//
//当中间元素大于或等于目标值时，右指针需要移动到中间位置，即 right = mid。因为中间位
// 置的元素可能就是我们要找的元素，所以不能排除它。
//
//循环应当在左指针大于右指针时结束。在大多数情况下，这意味着左右指针相遇。
            if (total_car_num >= cars) {
                time_max_limit = time_mid;
            } else {
                time_min_limit = time_mid + 1;
            }
        }
        return time_min_limit;
    }
};


int main() {
    Solution solution;
    vector<int> ranks = {4, 2, 3, 1};
    int cars = 10;
    cout << solution.repairCars(ranks, cars) << endl;

    ranks = {5, 1, 8};
    cars = 6;
    cout << solution.repairCars(ranks, cars) << endl;
    return 0;
}
