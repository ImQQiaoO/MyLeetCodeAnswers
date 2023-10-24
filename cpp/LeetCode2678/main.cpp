#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string> &details) {
        int cnt = 0;
        for (const string &str: details)
            if ((str[11] - '0') * 10 + (str[12] - '0') > 60) cnt++;
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
