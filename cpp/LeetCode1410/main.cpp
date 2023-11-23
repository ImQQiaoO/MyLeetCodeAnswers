#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {

    map<string, char> scm = {
            {"&quot;",  '"'},
            {"&apos;",  '\''},
            {"&amp;",   '&'},
            {"&gt;",    '>'},
            {"&lt;",    '<'},
            {"&frasl;", '/'},
    };

    unsigned int flag = 0;

public:
    string entityParser(string text) {
        string temp = "&";
        string res;
        for (size_t i = 0; i < text.size(); ++i) {
            if (flag == 1) {
                if (text[i] == ';') {
                    --flag;
                    temp += text[i];
                    cout << temp << endl;
                    if (scm.find(temp) != scm.end()) {
                        cout << "find!!!!!!!" << endl;
                        text[i] = scm[temp];
                        cout << text[i] << endl;
                        flag = 0;
                        temp = "";
                    }
                }
                temp += text[i];
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
            cout << res << endl;
            cout << "flag is: " << flag << endl;
        }
        return "";
    }
};

int main() {
    // text = "&amp; is an HTML entity but &ambassador; is not."
    Solution s;
    cout << s.entityParser("&amp; is an HTML entity but &ambassador; is not.") << endl;

    // // text = "and I quote: &quot;...&quot;"
//     Solution s1;
//     cout << s1.entityParser("and I quote: &quot;...&quot;") << endl;

    // // text = "Stay home! Practice on Leetcode :)"
    // Solution s2;
    // cout << s2.entityParser("Stay home! Practice on Leetcode :)") << endl;

    // // "x &gt; y &amp;&amp; x &lt; y is always false"
    // Solution s3;
    // cout << s3.entityParser("x &gt; y &amp;&amp; x &lt; y is always false") << endl;

    // // text = "leetcode.com&frasl;problemset&frasl;all"
    // Solution s4;
    // cout << s4.entityParser("leetcode.com&frasl;problemset&frasl;all") << endl;
    return 0;
}
