#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>> &coordinates) {
        // 计算出数组中前两个点连成的线的斜率
        deque<vector<int>> check_que(coordinates.begin(), coordinates.end());
        double slope = 0.0;
        bool is_first = true;
        while (check_que.size() != 1 && !check_que.empty()) {
            vector<int> point1 = check_que.front();
            check_que.pop_front();
            vector<int> point2 = check_que.front();
            if (is_first) {
                // 如果斜率不存在，说明是垂直于x轴的线
                if (point2[0] - point1[0] == 0) {
                    slope = numeric_limits<double>::max();
                } else {
                    slope = (double) (point2[1] - point1[1]) / (double) (point2[0] - point1[0]);
                }
                is_first = false;
            }

            double curr_slope;
            if (point2[0] - point1[0] == 0) {
                curr_slope = numeric_limits<double>::max();
            } else {
                curr_slope = (double) (point2[1] - point1[1]) / (double) (point2[0] - point1[0]);
            }

            if (curr_slope != slope) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    Solution s;
    vector<vector<int>> coordinates = {{1, 2},
                                       {2, 3},
                                       {3, 4},
                                       {4, 5},
                                       {5, 6},
                                       {6, 7}};
    cout << s.checkStraightLine(coordinates) << endl;


    // coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
    Solution s1;
    vector<vector<int>> coordinates1 = {{1, 1},
                                        {2, 2},
                                        {3, 4},
                                        {4, 5},
                                        {5, 6},
                                        {7, 7}};
    cout << s1.checkStraightLine(coordinates1) << endl;


    // [[0,0],[0,1],[0,-1]]
    Solution s2;
    vector<vector<int>> coordinates2 = {{0, 0},
                                        {0, 1},
                                        {0, -1}};
    cout << s2.checkStraightLine(coordinates2) << endl;
    return 0;
}
