#include <iostream>
#include <ostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        ListNode *temp = head;
        ListNode *first_zero = head;
        int32_t sum = 0;

        while (temp != nullptr) {
            if (temp->val != 0) {
                sum += temp->val;
                first_zero->next = temp->next;
                delete temp;
                temp = first_zero->next;
            } else {
                first_zero->val = sum;
                if (sum != 0 && first_zero->next->next != nullptr) {
                    first_zero = first_zero->next;
                }
                temp = temp->next;
                sum = 0;
            }
        }
        delete first_zero->next;
        first_zero->next = nullptr;
        return head;
    }
};

int main() {
    // head = [0,3,1,0,4,5,2,0]
    ListNode *head = new ListNode(0);
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(2);
    ListNode *node7 = new ListNode(0);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    Solution solution;
    ListNode *res = solution.mergeNodes(head);
    while (res != nullptr) {
        std::cout << res->val << std::endl;
        res = res->next;
    }

    std::cout << "-----------------------" << std::endl;

    // head = [0,1,0,3,0,2,2,0]
    ListNode *headA = new ListNode(0);
    ListNode *nodeA1 = new ListNode(1);
    ListNode *nodeA2 = new ListNode(0);
    ListNode *nodeA3 = new ListNode(3);
    ListNode *nodeA4 = new ListNode(0);
    ListNode *nodeA5 = new ListNode(2);
    ListNode *nodeA6 = new ListNode(2);
    ListNode *nodeA7 = new ListNode(0);
    headA->next =  nodeA1;
    nodeA1->next = nodeA2;
    nodeA2->next = nodeA3;
    nodeA3->next = nodeA4;
    nodeA4->next = nodeA5;
    nodeA5->next = nodeA6;
    nodeA6->next = nodeA7;
    Solution solutionA;
    ListNode *resA = solutionA.mergeNodes(headA);
    while (resA != nullptr) {
        std::cout << resA->val << std::endl;
        resA = resA->next;
    }

    return 0;
}
