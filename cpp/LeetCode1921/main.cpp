#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* LeetCode 1921 */

class Solution {
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
        int killed_num = 0;
        vector<double> residue_time;
        residue_time.reserve(dist.size());
        for (vector<double>::size_type i = 0; i < dist.size(); i++) {
            if (dist[i] == 0) return 0;
            residue_time.push_back(static_cast<double>(static_cast<double>(dist[i]) / speed[i]));
        }
        sort(residue_time.begin(), residue_time.end());
//        do {
////            residue_time.erase(residue_time.begin());
//            for (vector<double>::size_type i = killed_num; i < residue_time.size(); i++) {
//                residue_time[i] -= 1;
//            }
//            killed_num++;
//        } while (killed_num < residue_time.size() && residue_time[killed_num] > 0);

        for (double items : residue_time) {
            if (items > killed_num) {
                ++killed_num;
            } else {
                return killed_num;
            }
        }

        return killed_num;
    }

};

int main() {
    vector<int> dist1 = {1, 3, 4};
    vector<int> speed1 = {1, 1, 1};
    cout << Solution().eliminateMaximum(dist1, speed1) << endl;

    vector<int> dist2 = {1, 1, 2, 3};
    vector<int> speed2 = {1, 1, 1, 1};
    cout << Solution().eliminateMaximum(dist2, speed2) << endl;

    vector<int> dist3 = {3, 2, 4};
    vector<int> speed3 = {5, 3, 2};
    cout << Solution().eliminateMaximum(dist3, speed3) << endl;
    return 0;
}
 