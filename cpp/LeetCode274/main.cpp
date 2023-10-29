#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int res = 0;
        sort(citations.begin(), citations.end(), [](int a, int b) { return a > b; });
        for (size_t i = 0; i < citations.size(); ++i) {
            if (citations[i] >= i + 1) {
                res = i + 1;
            }
        }
        return res;
    }
};

int main() {
    // citations = [3,0,6,1,5]
    Solution s1;
    vector<int> citations1{3, 0, 6, 1, 5};
    s1.hIndex(citations1);
    cout << s1.hIndex(citations1) << endl;

    // citations = [1,3,1]
    Solution s2;
    vector<int> citations2{1, 3, 1};
    cout << s2.hIndex(citations2) << endl;
    return 0;
}
