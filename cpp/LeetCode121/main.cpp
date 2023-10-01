#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // O(n^2)的解法，超出时间限制
//        int highest = INT_MIN;
//        for (vector<int>::size_type i = 0; i != prices.size(); ++i) {
//            for (vector<int>::size_type j = i + 1; j != prices.size(); ++j) {
//                if (prices[j] - prices[i] > highest) {
//                    highest = prices[j] - prices[i];
//                }
//            }
//        }
//        if (highest < 0) {
//            return 0;
//        } else {
//            return highest;
//        }

        // O(n)的解法
        int lowest = INT_MAX;
        int highest = 0;
        for (int price : prices) {
            if (price < lowest) {
                lowest = price;
            } else if (price - lowest > highest) {
                highest = price - lowest;
            }
        }
        return highest;
    }
};

int main() {
    // [7,1,5,3,6,4]
    vector<int> prices0 = {7, 1, 5, 3, 6, 4};
    Solution s0;
    cout << s0.maxProfit(prices0) << endl;

    // [7,6,4,3,1]
    vector<int> prices1 = {7, 6, 4, 3, 1};
    Solution s1;
    cout << s1.maxProfit(prices1) << endl;

    return 0;
}
