#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() = default;

    void push(int val) {
        stk.push(val);
        if (aux.empty() || val <= aux.top())
            aux.push(val);
    }

    void pop() {
        if (aux.top() == stk.top())
            aux.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {  // O(1)复杂度
        return aux.top();
    }

private:
    stack<int> stk;
    stack<int> aux;
};


int main() {
    auto minStack = new MinStack();
    minStack->push(0);
    minStack->push(1);
    minStack->push(0);
    cout << minStack->getMin() << endl;   // --> 返回 -3.
    minStack->pop();
    cout << minStack->getMin() << endl;   // --> 返回 -2.
    delete minStack;

    return 0;
}
