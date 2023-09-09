#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        nums1.insert(nums1.cend(), nums2.begin(), nums2.begin() + n);
        sort(begin(nums1), end(nums1));
    }
};


int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution s;
    s.merge(nums1, 3, nums2, 3);
    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << endl;
    }
    return 0;
}
