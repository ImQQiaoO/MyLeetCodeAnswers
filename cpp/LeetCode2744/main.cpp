#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximumNumberOfStringPairs(vector<string> &words) {
		int res = 0;
		for (size_t i = 0; i < words.size(); ++i) {
			string temp_str = words[i];
			reverse(temp_str.begin(), temp_str.end());
			for (size_t j = i + 1; j < words.size(); ++j) {
				if (temp_str == words[j]) {
					++res;
				}
			}
		}
		return res;
	}
};

int main() {
	// words = ["cd","ac","dc","ca","zz"]
	Solution s0;
	vector<string> words = { "cd","ac","dc","ca","zz" };
	cout << s0.maximumNumberOfStringPairs(words) << endl;

	// words = ["ab","ba","cc"]
	Solution s1;
	vector<string> words1 = { "ab","ba","cc" };
	cout << s1.maximumNumberOfStringPairs(words1) << endl;

	// words = ["aa","ab"]
	Solution s2;
	vector<string> words2 = { "aa","ab" };
	cout << s2.maximumNumberOfStringPairs(words2) << endl;
	return 0;
}
