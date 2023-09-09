#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

/* LeetCode 150 */

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stack;
        for (auto &item: tokens) {
            if (item == "+" || item == "-" || item == "*" || item == "/") {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                if (item == "+") stack.push(num2 + num1);
                else if (item == "-") stack.push(num2 - num1);
                else if (item == "*") stack.push(num2 * num1);
                else if (item == "/") stack.push(num2 / num1);
            } else {
                stack.push(stoi(item));
            }
        }
        return stack.top();
    }
};

int main() {
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution solution;
    cout << solution.evalRPN(tokens) << endl;
    return 0;
}
