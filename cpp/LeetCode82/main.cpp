#include <iostream>
#include <vector>

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
        vector<int> del_nums;
        while (curr->next != nullptr) {
            curr = curr->next;
            if (curr->val == last_node->val) {
                del_nums.push_back(curr->val);
                last_node->next = curr->next;
            } else {
                last_node = curr;
            }
        }
        // 删除del_nums中保存的节点
        for (size_t i = 0; i < del_nums.size(); ++i) {
            // 删除链表中的节点
            auto curr0 = head;
            auto last_node0 = curr0;
            while (curr0 != nullptr) {
                if (curr0->val == del_nums[i]) {
                    if (curr0 == head) {
                        head = head->next;
                        curr0 = head;
                        last_node0 = curr0;
                    } else {
                        last_node0->next = curr0->next;
                        curr0 = curr0->next;
                    }
                } else {
                    last_node0 = curr0;
                    curr0 = curr0->next;
                }
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
