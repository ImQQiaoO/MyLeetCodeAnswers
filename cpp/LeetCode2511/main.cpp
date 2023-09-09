#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int captureForts(vector<int> &forts) {
        int res = 0;
        int cnt = 0;
        size_t sentinel = -1;

        for (vector<int>::size_type i = 0; i < forts.size(); ++i) { // 双指针， o(n)
            if (forts[i] == 1 || forts[i] == -1) {
                if (sentinel == -1) {
                    sentinel = i;
                }
                if (forts[sentinel] == -forts[i]) {
                    if (res < cnt) {
                        res = cnt;
                    }
                }
                cnt = 0;
                sentinel = i;
            } else if (forts[i] == 0) {
                cnt++;
            }
        }
        return res;
    }
};

int main() {
    vector<int> forts{0,0,1,-1};
    cout << Solution().captureForts(forts) << endl;
    return 0;
}
