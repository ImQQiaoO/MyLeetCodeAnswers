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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 快慢指针
        auto fast = head;
        auto slow = head;
        // 1.首先让fast指针领先n个节点
        int cnt = 0;
        while (cnt != n - 1) {
            ++cnt;
            fast = fast->next;
        }
        // 2.然后让fast和slow指针同时向后移动，直到fast指针指向最后一个节点
        ListNode *prev = nullptr;
        while (fast->next != nullptr) {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        // 3.此时slow指针指向倒数第n个节点，删除该节点
        if (prev == nullptr) {
            // 删除的是头节点
            auto temp = head;
            head = head->next;
            delete temp;
        } else {
            prev->next = slow->next;
            delete slow;
        }
        return head;
    }
};

int main() {
    // 1->2->3->4->5, and n = 2.
    auto head = new ListNode(1);
    auto node1 = new ListNode(2);
    auto node2 = new ListNode(3);
    auto node3 = new ListNode(4);
    auto node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    Solution s;
    auto res = s.removeNthFromEnd(head, 2);
    // 输出res
    auto temp = res;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // head = [1], n = 1
    auto head1 = new ListNode(1);
    auto res1 = s.removeNthFromEnd(head1, 1);
    // 输出res
    auto temp1 = res1;
    while (temp1 != nullptr) {
        cout << temp1->val << " ";
        temp1 = temp1->next;
    }
    cout << endl;

    // head = [1,2], n = 1
    auto head2 = new ListNode(1);
    auto node5 = new ListNode(2);
    head2->next = node5;
    auto res2 = s.removeNthFromEnd(head2, 1);
    // 输出res
    auto temp2 = res2;
    while (temp2 != nullptr) {
        cout << temp2->val << " ";
        temp2 = temp2->next;
    }
    cout << endl;
    return 0;
}
