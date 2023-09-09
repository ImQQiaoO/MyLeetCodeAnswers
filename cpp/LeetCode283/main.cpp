#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto res = remove(nums.begin(), nums.end(), 0);
        while (res != nums.end()) {
            *res = 0;
            res++;
        }
    }
};

int main() {
    Solution s;
    vector<int> v = {0, 1, 0, 3, 12};
    s.moveZeroes(v);
    for (auto i: v) {
        cout << i << " ";
    }
    return 0;
}
