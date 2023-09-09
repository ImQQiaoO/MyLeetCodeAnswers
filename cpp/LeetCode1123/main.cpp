#include <algorithm>
#include <iostream>

using namespace std;

/* LeetCode 1123 */

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
    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        return dfs(root).first;
    }

    pair<TreeNode *, int> dfs(TreeNode *node) {
        if (node == nullptr) {
            return {nullptr, 0};
        }

        pair<TreeNode *, int> left = dfs(node->left);
        pair<TreeNode *, int> right = dfs(node->right);

        if (left.second == right.second) {  // 如果该节点的左右子树的最大深度相同，则该节点为最深叶子节点的公共祖先
            return {node, left.second + 1};
        } else if (left.second > right.second) {    // 如果该节点的左子树的最大深度大于右子树的最大深度，则该节点的左子树为最深叶子节点的公共祖先
            return {left.first, left.second + 1};
        } else {    // 如果该节点的右子树的最大深度大于左子树的最大深度，则该节点的右子树为最深叶子节点的公共祖先
            return {right.first, right.second + 1};
        }
    }
};



int main() {
    Solution solution;

    auto *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = nullptr;
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->left->left->left = nullptr;
    root2->left->left->right = new TreeNode(5);
    root2->left->right->left = nullptr;
    root2->left->right->right = new TreeNode(6);
    TreeNode *result2 = solution.lcaDeepestLeaves(root2);

    cout << result2->val << endl;


    return 0;
}
