#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> touched = {1};
        vector<int> untouched;
        bool repeat = false;
        for (int i = 1; !repeat; ++i) {
            int new_val = (touched.back() + (k * i) % n) % n;
//            cout << "new val is: " << new_val << endl;
            if (new_val == 0) new_val = n; // 处理new_val等于0的情况
            for (int j : touched) {
                if (new_val == j) {
                    repeat = true;
                }
            }
            if (!repeat)
                touched.push_back(new_val);
        }
        for (int i = 1; i <= n; ++i) {
            untouched.push_back(i);
        }
        sort(touched.begin(), touched.end());
        vector<int> result;
        set_difference(untouched.begin(), untouched.end(), touched.begin(), touched.end(), back_inserter(result));
        return result;
    }
};

int main() {
    Solution s;
    vector<int> res = s.circularGameLosers(5, 2);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> res1 = s.circularGameLosers(4, 4);
    for (auto i : res1) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> res2 = s.circularGameLosers(2, 1);
    for (auto i : res2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
