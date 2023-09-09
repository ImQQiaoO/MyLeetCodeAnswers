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
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};

int main() {
    Solution sol;

    // 10 4 6
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    cout << sol.checkTree(root) << endl;

    // 5 3 1
    auto root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(1);
    cout << sol.checkTree(root1) << endl;

    return 0;
}
