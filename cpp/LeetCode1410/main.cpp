#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {

    map<string, char> scm = {
            {"&quot;"   ,   '"'  },
            {"&apos;"   ,   '\'' },
            {"&amp;"    ,   '&'  },
            {"&gt;"     ,   '>'  },
            {"&lt;"     ,   '<'  },
            {"&frasl;"  ,   '/'  },
    };
    unsigned int flag = 0;
    vector<pair<size_t, int>> to_delete;

    void cut(string &text) {
        int temp = 0;
        for (size_t i = 0; i < to_delete.size(); ++i) {
            if (i > 0) {
                temp += to_delete[i - 1].first;
                to_delete[i].second = to_delete[i].second - temp;
            }
            text.erase(to_delete[i].second - to_delete[i].first, to_delete[i].first);
        }
    }

public:
    string entityParser(string text) {
        string temp = "&";
        for (size_t i = 0; i < text.size(); ++i) {

            if (flag > 0) {
                ++flag;
                if (text[i] == ';') {
                    temp += text[i];
                    if (scm.find(temp) != scm.end()) {
                        text[i] = scm[temp];
                        // 不能用绝对位置，因为删除后，后面的位置会变化
                        to_delete.emplace_back(flag - 1, i);
                        flag = 0;
                        temp = "&";
                        continue;
                    }
                    flag = 0;
                } else {
                    temp += text[i];
                }
                // 剪枝
                if (temp.size() > 7) {
                    flag = 0;
                    temp = "&";
                }
            }
            if (text[i] == '&') {
                if (flag != 0) {
                    temp = "&";
                    flag = 0;
                }
                ++flag;
            }
        }
        cut(text);
        return text;
    }
};

int main() {
    //text = "&amp; is an HTML entity but &ambassador; is not."
    Solution s;
    cout << s.entityParser("&amp; is an HTML entity but &ambassador; is not.") << endl;
    cout << endl;

    //text = "and I quote: &quot;...&quot;"
    Solution s1;
    cout << s1.entityParser("and I quote: &quot;...&quot;") << endl;
    cout << endl;

    //text = "Stay home! Practice on Leetcode :)"
    Solution s2;
    cout << s2.entityParser("Stay home! Practice on Leetcode :)") << endl;
    cout << endl;

    //"x &gt; y &amp;&amp; x &lt; y is always false"
    Solution s3;
    cout << s3.entityParser("x &gt; y &amp;&amp; x &lt; y is always false") << endl;
    cout << endl;

    //text = "leetcode.com&frasl;problemset&frasl;all"
    Solution s4;
    cout << s4.entityParser("leetcode.com&frasl;problemset&frasl;all") << endl;
    cout << endl;

    //text = "&amp;amp;"
    Solution s5;
    cout << s5.entityParser("&amp;amp;") << endl;
    cout << endl;
    return 0;
}
