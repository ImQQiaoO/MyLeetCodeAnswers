#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        for (int i = 0; i < k; ++i) {
            auto res = max_element(gifts.begin(), gifts.end());
            *res = sqrt(*res);
        }
        long long sum = 0;
        for (const int &gift : gifts) {
            sum += gift;
        }
        return sum;
    }
};

int main() {
    Solution s1;
    vector<int> gifts1{25, 64, 9, 4, 100};
    int k1 = 4;
    cout << s1.pickGifts(gifts1, k1) << endl;

    vector<int> gifts2{1,1,1,1};
    int k2 = 4;
    cout << s1.pickGifts(gifts2, k2) << endl;
    return 0;
}
