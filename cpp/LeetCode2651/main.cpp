#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};

int main() {
    cout << Solution().findDelayedArrivalTime(15, 5) << endl;
    cout << Solution().findDelayedArrivalTime(13, 11) << endl;

    return 0;
}
