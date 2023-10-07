#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsPattern(vector<int> &arr, int m, int k) {  // m : 元素个数 k : 重复次数
        int n = static_cast<int>(arr.size());
        if (n < m * k) {
            return false;
        }
        for (int i = 0; i <= n - m * k; ++i) {
            bool flag = true;
            for (int j = 0; j < m * k; ++j) {
                if (arr[i + j] != arr[i + j % m]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // [1,2,4,4,4,4]
    vector<int> arr0 = {1, 2, 4, 4, 4, 4};
    int m0 = 1;
    int k0 = 3;
    Solution s0;
    cout << s0.containsPattern(arr0, m0, k0) << endl;

    // [1,2,1,2,1,1,1,3]
    vector<int> arr1 = {1, 2, 1, 2, 1, 1, 1, 3};
    int m1 = 2;
    int k1 = 2;
    Solution s1;
    cout << s1.containsPattern(arr1, m1, k1) << endl;

    // [1,2,1,2,1,3]
    vector<int> arr2 = {1, 2, 1, 2, 1, 3};
    int m2 = 2;
    int k2 = 3;
    Solution s2;
    cout << s2.containsPattern(arr2, m2, k2) << endl;

    // [1,2,3,1,2]
    vector<int> arr3 = {1, 2, 3, 1, 2};
    int m3 = 2;
    int k3 = 2;
    Solution s3;
    cout << s3.containsPattern(arr3, m3, k3) << endl;

    // [2,2,2,2]
    vector<int> arr4 = {2, 2, 2, 2};
    int m4 = 2;
    int k4 = 3;
    Solution s4;
    cout << s4.containsPattern(arr4, m4, k4) << endl;

    return 0;
}
