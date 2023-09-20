#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCount(vector<int> &coins) {
        int res = 0;
        for (vector<int>::size_type i = 0; i < coins.size(); ++i) {
            if (coins[i] % 2 == 0) {
                res += coins[i] / 2;
            } else {
                res += coins[i] / 2 + 1;
            }
        }
        return res;
    }
};

int main() {
    // [4,2,1]
    
    return 0;
}
