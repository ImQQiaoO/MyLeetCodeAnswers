#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;
        for (char c : magazine) {
            m[c]++;
        }
        for (char c : ransomNote) {
            if (m[c] == 0) {
                return false;
            }
            m[c]--;
        }
        return true;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
