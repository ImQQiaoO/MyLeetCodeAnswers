#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int key;
    int val;

    Node *prev;
    Node *next;

    Node(int key, int val) : key(key), val(val) {}
};

class LRUCache {
private:
    int size;
    Node *dummy;
    unordered_map<int, Node *> key_to_node;

    void push_front(Node *n) {
        n->prev = dummy;
        n->next = dummy->next;
        dummy->next->prev = n;
        dummy->next = n;
        //        n->prev->next = n;
        //        n->next->prev = n;
    }

    void remove(Node *n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    Node *get_node(int key) {
        /*    // Time Complexity: O(n)
            Node *cur = dummy->next;
            while (cur != dummy) {
                if (cur->key == key) {
                    return cur;
                }
                cur = cur->next;
            }
        */
        // 未找到
        auto iter = key_to_node.find(key);
        if (iter == key_to_node.end()) {
            return nullptr;
        }
        // 找到了
        auto node = iter->second;
        // 将此节点放到最上面
        remove(node);
        push_front(node);
        return node;
    }

public:
    // Destructor
    ~LRUCache() {
        Node *cur = dummy->next;
        while (cur != dummy) {
            Node *tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        delete dummy;
    }

    // Copy constructor
    LRUCache(const LRUCache &other) : size(other.size) {
        dummy = new Node(-1, -1);
        dummy->prev = dummy;
        dummy->next = dummy;
        for (auto &[key, node]: other.key_to_node) {
            auto new_node = new Node(node->key, node->val);
            key_to_node[key] = new_node;
            push_front(new_node);
        }
    }

    // Copy assignment operator
    LRUCache &operator=(const LRUCache &other) {
        if (this == &other) {
            return *this;
        }
        size = other.size;
        Node *cur = dummy->next;
        while (cur != dummy) {
            Node *tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        key_to_node.clear();
        dummy->prev = dummy;
        dummy->next = dummy;
        for (auto &[key, node]: other.key_to_node) {
            auto new_node = new Node(node->key, node->val);
            key_to_node[key] = new_node;
            push_front(new_node);
        }
        return *this;
    }

    /* Provided by leetcode */
    LRUCache(int capacity) : size(capacity) {
        dummy = new Node(-1, -1);
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    int get(int key) {
        auto curr_node = get_node(key);
        if (curr_node == nullptr) {
            return -1;
        }
        return curr_node->val;
    }

    void put(int key, int value) {
        auto has_node = get_node(key);
        if (has_node != nullptr) {
            has_node->val = value;
            return;
        }
        // 如果此节点不存在
        auto new_node = new Node(key, value);
        key_to_node[key] = new_node;// 更新散列表
        push_front(new_node);
        // 如果超出了容量
        if (key_to_node.size() > size) {
            auto to_be_deleted = dummy->prev;
            key_to_node.erase(to_be_deleted->key);
            remove(to_be_deleted);
            delete to_be_deleted;// 释放内存
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    // ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    // [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    auto *obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    obj->put(4, 4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
    return 0;
}
