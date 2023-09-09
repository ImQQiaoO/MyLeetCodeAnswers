#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes) {
        int sumChangedBob = 0;
        int totalSum = 0;
        for (int aliceSize : aliceSizes) {
            totalSum += aliceSize;
        }
        for (int bobSize : bobSizes) {
            totalSum += bobSize;
        }
        for (int i = 0; i < aliceSizes.size(); ++i) {
            for (int j = 0; j < bobSizes.size(); ++j) {
                if (i != j) {
                    sumChangedBob += bobSizes[j];
                }
                sumChangedBob = sumChangedBob + aliceSizes[i];
                if (sumChangedBob == totalSum / 2) {
                    static vector<int> res;
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        return {};
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<int> aliceSizes = {1, 1};
    vector<int> bobSizes = {2, 2};
    vector<int> result = solution.fairCandySwap(aliceSizes, bobSizes);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
