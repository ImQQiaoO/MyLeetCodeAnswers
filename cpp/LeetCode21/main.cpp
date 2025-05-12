#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* last = &dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                last->next = list1;
                list1 = list1->next;
            } else {
                last->next = list2;
                list2 = list2->next;
            }
            last = last->next;
        }
        if (list1 != nullptr) {
            last->next = list1;
        }
        if (list2 != nullptr) {
            last->next = list2;
        }
        return dummy.next;
    }
};

int main() {
    // l1 = [1,2,4], l2 = [1,3,4]
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    Solution solution;
    ListNode *result = solution.mergeTwoLists(l1, l2);
    // Print the merged list
    ListNode *current = result;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // l1 = [], l2 = []
    l1 = nullptr;
    l2 = nullptr;
    result = solution.mergeTwoLists(l1, l2);
    // Print the merged list
    current = result;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // l1 = [], l2 = [0]
    l1 = nullptr;
    l2 = new ListNode(0);
    result = solution.mergeTwoLists(l1, l2);
    // Print the merged list
    current = result;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // l1 = [2], l2 = [1]
    l1 = new ListNode(2);
    l2 = new ListNode(1);
    result = solution.mergeTwoLists(l1, l2);
    // Print the merged list
    current = result;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
