#include <iostream>
#include <cmath>


using namespace std;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool isBulky = false;
        bool isHeavy = false;
        unsigned long long int v = static_cast<unsigned long long int>(length) * static_cast<unsigned long long int>(width) * static_cast<unsigned long long int>(height);
        if (length >= pow(10, 4) || width >= pow(10, 4) || height >= pow(10, 4)
            || v >= pow(10, 9)) {
            isBulky = true;
        }
        if (mass >= pow(10, 2)) {
            isHeavy = true;
        }
//        cout << "isBulky: " << isBulky << endl;
//        cout << "isHeavy: " << isHeavy << endl;
        if (isBulky && isHeavy) {
            return "Both";
        } else if (isBulky) {
            return "Bulky";
        } else if (isHeavy) {
            return "Heavy";
        } else {
            return "Neither";
        }
    }
};

int main() {
    // length = 1000, width = 35, height = 700, mass = 300
    Solution solution0;
    cout << solution0.categorizeBox(1000, 35, 700, 300) << endl;

    // length = 200, width = 50, height = 800, mass = 50
    Solution solution1;
    cout << solution1.categorizeBox(200, 50, 800, 50) << endl;
    return 0;
}
