#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator) {
        for (size_t i = 0; i < words.size(); ) {
            // 如果当前字符串中只有分隔符，则删除该字符串
            if (words[i].find_first_not_of(separator) == string::npos) {
                words.erase(words.begin() + i);
                continue;
            }
            string_split(words, words.begin() + i, separator);
            i++;
        }
        return words;
    }

private:

    unsigned int get_separator_num(const string &str, char separator) {
        unsigned int num = 0;
        for (const auto &ch : str) {
            if (ch == separator) {
                ++num;
            }
        }
        return num;
    }

    void string_split(vector<string> &words, vector<string>::iterator iter, char separator) {
        const unsigned int separator_cnt = get_separator_num(*iter, separator);
        if (separator_cnt == 0) {
            return;
        }
        stringstream ss(*iter);
        string item;
        unsigned int temp_cnt = 0;
        while (temp_cnt < separator_cnt + 1 && getline(ss, item, separator)) {
            if (!item.empty()) {
                iter = words.insert(iter + 1, item);
                ++temp_cnt;
            }
        }
        words.erase(iter - temp_cnt);
    }
};


void print_vec(const vector<string> &res) {
    cout << "[";
    for (auto iter = res.begin(); iter != res.end(); ++iter) {
        if (iter != res.begin()) {
            cout << ", ";
        }
        cout << *iter;
    }
    cout << "]";
}

int main() {
    vector<string> words0 = {"one.two.three", "four.five", "six"};
    char separator0 = '.';
    Solution solution0;
    solution0.splitWordsBySeparator(words0, separator0);
    print_vec(words0);
    cout << "\n";

    vector<string> words1 = {"$easy$", "$problem$"};
    char separator1 = '$';
    Solution solution1;
    solution1.splitWordsBySeparator(words1, separator1);
    print_vec(words1);
    cout << "\n";

    vector<string> words2 = {"|||"};
    char separator2 = '|';
    Solution solution2;
    solution2.splitWordsBySeparator(words2, separator2);
    print_vec(words2);
    cout << "\n";

    vector<string> words3 = {"#", "#"};
    char separator3 = '#';
    Solution solution3;
    solution3.splitWordsBySeparator(words3, separator3);
    print_vec(words3);
    cout << "\n";

    return 0;
}
