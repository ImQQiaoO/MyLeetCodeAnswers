#include <iostream>

using namespace std;

struct ListNode {

    friend ostream &operator<<(ostream &os, const ListNode *node) {		// FOR DEBUG
        while (node != nullptr) {
            os << node->val << " ";
            node = node->next;
        }
        return os;
    }

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    auto deleteDuplicates(ListNode *head) -> ListNode * {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto curr = head;
        auto last_node = curr;
        while (curr->next != nullptr) {
            curr = curr->next;
            if (curr->val == last_node->val) {
                last_node->next = curr->next;
            } else {
                last_node = curr;
            }
        }
        return head;
    }
};


int main() {
    // head = [1,1,2]
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    Solution s1;
    cout << s1.deleteDuplicates(head) << endl;

    // head = [1,1,2,3,3]
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(1);
    head1->next->next = new ListNode(2);
    head1->next->next->next = new ListNode(3);
    head1->next->next->next->next = new ListNode(3);
    Solution s2;
    cout << s2.deleteDuplicates(head1) << endl;

    return 0;
}
