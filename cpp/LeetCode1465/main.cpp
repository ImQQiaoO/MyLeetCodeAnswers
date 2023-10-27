#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        // 申请数组        

        long long int max_h = 0;
        long long int max_w = 0;

        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());

        horizontalCuts.insert(horizontalCuts.begin(),0);
        horizontalCuts.push_back(h);
        verticalCuts.insert(verticalCuts.begin(),0);
        verticalCuts.push_back(w);

        for (size_t i = 1; i < horizontalCuts.size(); ++i) {
            if (horizontalCuts[i] - horizontalCuts[i - 1] > max_h) {
                max_h = horizontalCuts[i] - horizontalCuts[i - 1];
            }
        }
        for (size_t j = 1; j < verticalCuts.size(); ++j) {
            if (verticalCuts[j] - verticalCuts[j - 1] > max_w) {
                max_w = verticalCuts[j] - verticalCuts[j - 1];
            }
        }

        return (max_h * max_w) % 1000000007;

    }
};

int main() {
    Solution s1;
    int h1 = 5, w1 = 4;
    vector<int> horizontalCuts1 = {1, 2, 4}, verticalCuts1 = {1, 3};
    cout << s1.maxArea(h1, w1, horizontalCuts1, verticalCuts1) << endl;

    Solution s2;
    int h2 = 5, w2 = 4;
    vector<int> horizontalCuts2 = {3, 1}, verticalCuts2 = {1};
    cout << s2.maxArea(h2, w2, horizontalCuts2, verticalCuts2) << endl;

    Solution s3;
    int h3 = 5, w3 = 4;
    vector<int> horizontalCuts3 = {3}, verticalCuts3 = {3};
    cout << s3.maxArea(h3, w3, horizontalCuts3, verticalCuts3) << endl;

    Solution s4;
    int h4 = 1000000000, w4 = 1000000000;
    vector<int> horizontalCuts4 = {2}, verticalCuts4 = {2};
    cout << s4.maxArea(h4, w4, horizontalCuts4, verticalCuts4) << endl;
    return 0;
}
