#include <iostream>
#include <algorithm>

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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        // 如果当前节点不是叶子节点，则递归判断其子节点
        return hasPathSum(root->left, targetSum - root->val) ||
            hasPathSum(root->right, targetSum - root->val);
    }
};

int main() {
    // root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    auto *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->right = nullptr;
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left->left = nullptr;
    root->right->left->right = nullptr;
    root->right->right->left = nullptr;
    root->right->right->right = new TreeNode(1);
    Solution solution;
    int result = solution.hasPathSum(root, 22);
    cout << result << endl;

    // root = [1,2,3], targetSum = 5
    auto *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    Solution solution2;
    int result2 = solution2.hasPathSum(root2, 5);
    cout << result2 << endl;

    // root = [1,2], targetSum = 1
    auto *root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    Solution solution3;
    int result3 = solution3.hasPathSum(root3, 1);
    cout << result3 << endl;

    auto *root4 = new TreeNode(1);
    Solution solution4;
    int result4 = solution4.hasPathSum(root4, 1);
    cout << result4 << endl;

    return 0;
}