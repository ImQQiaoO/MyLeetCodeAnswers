#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    static bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' ||
               c == 'u';
    }
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i) {
            string word = words[i];
            if (isVowel(word[0]) && isVowel(word[word.length() - 1])) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    // words0 = ["are","amy","u"], left0 = 0, right0 = 2
    vector<string> words0 = {"are", "amy", "u"};
    int left0 = 0, right0 = 2;
    Solution s0;
    cout << s0.vowelStrings(words0, left0, right0) << endl;

    // words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
    vector<string> words1 = {"hey", "aeo", "mu", "ooo", "artro"};
    int left1 = 1, right1 = 4;
    Solution s1;
    cout << s1.vowelStrings(words1, left1, right1) << endl;


    return 0;
}
