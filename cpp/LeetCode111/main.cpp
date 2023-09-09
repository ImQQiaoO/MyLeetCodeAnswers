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

    // root = [3,9,20,null,null,15,7]
    auto *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution solution;
    int result = solution.minDepth(root);
    cout << result << endl;


    // root = [2,null,3,null,4,null,5,null,6]
    auto *root2 = new TreeNode(2);
    root2->left = nullptr;
    root2->right = new TreeNode(3);
    root2->right->left = nullptr;
    root2->right->right = new TreeNode(4);
    root2->right->right->left = nullptr;
    root2->right->right->right = new TreeNode(5);
    root2->right->right->right->left = nullptr;
    root2->right->right->right->right = new TreeNode(6);
    int result2 = solution.minDepth(root2);
    cout << result2 << endl;
    return 0;
}
