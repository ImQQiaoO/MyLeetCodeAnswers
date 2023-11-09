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
    ListNode* rotateRight(ListNode* head, int k) {
        // 链表为空
        if (head == nullptr) {
            return nullptr;
        }
        // 链表只有一个元素
        if (head->next == nullptr) {
            return head;
        }
        // 统计链表长度
        int len = 0;
        ListNode *p = head;
        while (p != nullptr) {
            len++;
            p = p->next;
        }
        // 对k取余
        k = k % len;
        // k == 0
        if (k == 0) {
            return head;
        }
        // 移动链表
        int curr_num = 0;
        p = head;
        ListNode *temp = nullptr;
        while (curr_num != len - k) {
            if (curr_num == len - k - 1) {
                temp = p->next;
                p->next = nullptr;  // 断开链表
            }
            ++curr_num;
            p = p->next;
        }
        // 重新连接链表
        p = temp;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = head;
        return temp;
    }
};

int main() {
    // head = [1,2,3,4,5], k = 2
    Solution s0;
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    auto *res = s0.rotateRight(head, 2);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    // head = [0,1,2], k = 4
    Solution s1;
    ListNode *head1 = new ListNode(0);
    ListNode *node11 = new ListNode(1);
    ListNode *node12 = new ListNode(2);
    head1->next = node11;
    node11->next = node12;
    auto *res1 = s1.rotateRight(head1, 4);
    while (res1 != nullptr) {
        cout << res1->val << " ";
        res1 = res1->next;
    }
    cout << endl;

    // head = [1,2], k = 1
    Solution s2;
    ListNode *head2 = new ListNode(1);
    ListNode *node21 = new ListNode(2);
    head2->next = node21;
    auto *res2 = s2.rotateRight(head2, 1);
    while (res2 != nullptr) {
        cout << res2->val << " ";
        res2 = res2->next;
    }
    return 0;
}
