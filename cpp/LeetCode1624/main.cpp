#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char, int> m;
        int max_length = 0;
        bool flag = false;;
        for (size_t i = 0; i < s.size(); ++i) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = i;
            } else {
                flag = true;
               if (i - m[s[i]] - 1 > max_length) {
                   max_length = i - m[s[i]] - 1;
               }
            }
        }
        if (!flag) {
            return -1;
        }
        return max_length;
    }
};


int main() {
    Solution s0;
    string str0 = "aaaa";
    cout << s0.maxLengthBetweenEqualCharacters(str0) << endl;

    Solution s1;
    string str1 = "abca";
    cout << s1.maxLengthBetweenEqualCharacters(str1) << endl;

    Solution s2;
    string str2 = "cbzxy";
    cout << s2.maxLengthBetweenEqualCharacters(str2) << endl;
    return 0;
}
