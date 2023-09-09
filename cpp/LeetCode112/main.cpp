#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {// dfs
        if (root == nullptr) {
            return 0;
        }
        int curr = 0;
        int min = INT_MAX;
        dfs(root, curr, min);
        return min;
    }

    void dfs(TreeNode *node, int curr, int &min) {
        if (node == nullptr) {
            return;
        }
        if (node->left == nullptr && node->right == nullptr) {
            min = std::min(min, curr + 1);
            return;
        }
        curr++;
        dfs(node->left, curr, min);
        dfs(node->right, curr, min);
    }
};

int main() {
    cout << "hi" <<  endl;
}