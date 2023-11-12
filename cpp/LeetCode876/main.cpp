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
    ListNode* middleNode(ListNode* head) {
        // 快慢指针
        auto slow = head;
        auto fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next != nullptr)
            slow = slow->next;
        return slow;
    }
};

int main() {
    // head = [1,2,3,4,5]
    Solution s0;
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    cout << s0.middleNode(head)->val << endl;

    // head = [1,2,3,4,5,6]
    Solution s1;
    ListNode* head1 = new ListNode(1);
    ListNode* node11 = new ListNode(2);
    ListNode* node21 = new ListNode(3);
    ListNode* node31 = new ListNode(4);
    ListNode* node41 = new ListNode(5);
    ListNode* node51 = new ListNode(6);
    head1->next = node11;
    node11->next = node21;
    node21->next = node31;
    node31->next = node41;
    node41->next = node51;
    cout << s1.middleNode(head1)->val << endl;
    
    return 0;
}
