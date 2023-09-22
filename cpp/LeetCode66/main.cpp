#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = static_cast<int>(digits.size());
        for (int i = size; i > 0; i--) {
            if (digits[i - 1] == 9) {
                digits[i - 1] = 0;
            } else {
                digits[i - 1] += 1;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};


void print_vec(vector<int> &digits) {
    for (auto i : digits) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    // digits = [1,2,3]
    Solution s1;
    vector<int> digits1{1, 2, 3};
    auto ans = s1.plusOne(digits1);
    print_vec(ans);

    // digits = [4,3,2,1]
    Solution s2;
    vector<int> digits2{4, 3, 2, 1};
    auto ans1 = s2.plusOne(digits2);
    print_vec(ans1);

    // digits = [0]
    Solution s3;
    vector<int> digits3{0};
    auto ans2 = s3.plusOne(digits3);
    print_vec(ans2);

    // digits = [9]
    Solution s4;
    vector<int> digits4{9};
    auto ans3 = s4.plusOne(digits4);
    print_vec(ans3);

    // digits = [9,9]
    Solution s5;
    vector<int> digits5{9, 9};
    auto ans4 = s5.plusOne(digits5);
    print_vec(ans4);

    // digits = [1,1,9]
    Solution s6;
    vector<int> digits6{1, 1, 9};
    auto ans5 = s6.plusOne(digits6);
    print_vec(ans5);

    return 0;
}
