#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
      ListNode *reverseList(ListNode *head) {
        if (!head){
            return nullptr;
        }
        ListNode *p, *r;
        p = head->next;
        head->next = nullptr;
        while (p != nullptr) {
            r = p->next;
            p->next = head;
            head = p;
            p = r;
        }
        return head;
    }
};

int main() {
    //head = [1,2,3,4,5]
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    auto result = s.reverseList(head);
    while (result != nullptr) {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}
