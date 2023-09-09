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

void deleteTree(TreeNode *node) {
    // 实际上这也是一种深度优先搜索
    if (node == nullptr) {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

class Solution {
public:
    int maxDepth(TreeNode *root) {
        // 深度优先搜索
        int res = 0;
        int curr = 0;
        dfs(root, curr, res);
        return res;
    }

    void dfs(TreeNode *node, int curr, int &res) {
        if (node == nullptr) {
            return;
        }
        curr++;
        res = max(res, curr);
        dfs(node->left, curr, res);
        dfs(node->right, curr, res);
    }
};

int main() {
    Solution solution;
    auto *root = new TreeNode(3,
                              new TreeNode(9),
                              new TreeNode(20,
                                           new TreeNode(15), new TreeNode(7)));
    cout << solution.maxDepth(root) << endl;
    deleteTree(root);
    return 0;
}
