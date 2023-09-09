#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* LeetCode 849 */

class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        // 1. 获取到左端连续的0的个数
        int left_head = 0;
        if (seats[0] == 0) {
            for (int i = 0; i < seats.size(); ++i) {
                if (seats[i] == 0) {
                    left_head++;
                } else {
                    break;
                }
            }
        }
        //        cout << "lh is: " << left_head << endl;
        // 2. 获取到右端连续的0的个数
        int right_head = 0;
        auto reverse_it = seats.rbegin();
        if (*reverse_it == 0) {
            for (; reverse_it != seats.rend(); reverse_it++) {
                if (*reverse_it == 0) {
                    right_head++;
                } else {
                    break;
                }
            }
        }
        //        cout << "rh is: " << right_head << endl;
        // 3. 比较两端连续的数的个数，取最大值
        int max_head = max(left_head, right_head);
        // 4. 获取到中间连续的0的个数
        vector<int> seated_people;
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 1) {
                seated_people.push_back(i);
            }
        }
        int max_gap = 0;
        if (seated_people.size() > 1) {
            for (int i = 1; i < seated_people.size(); ++i) {
                int temp = seated_people[i] - seated_people[i - 1] - 1;
                if (temp > max_gap) {
                    max_gap = temp;
                }
            }
        }
        return max(max_head, (max_gap + 1) / 2);
    }
};

void test(vector<int> &a) {
    a.push_back(0);
}

int main() {
    Solution s;
    vector<int> v{0, 1, 0, 0, 0, 0, 0, 1, 0, 0};
    cout << "v is: " << s.maxDistToClosest(v) << endl;
    vector<int> v1{1, 1, 0, 0};
    cout << "v1 is: " << s.maxDistToClosest(v1) << endl;
    vector<int> v2{1, 0, 0, 1};
    cout << "v2 is: " << s.maxDistToClosest(v2) << endl;
    vector<int> v3{1, 1, 0, 0, 1};
    cout << "v3 is: " << s.maxDistToClosest(v3) << endl;

    vector<int> a;
    test(a);
    int m = a.size();
    cout << "size of a is: " << m << endl;
    return 0;
}
