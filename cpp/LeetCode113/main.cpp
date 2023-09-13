#include <iostream>
#include <vector>

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
    vector<vector<int>> pathSum(TreeNode *node, int targetSum) {
        vector<vector<int>> res;
        if (node == nullptr) {
            return {};
        }
        if (node->left == nullptr && node->right == nullptr) {
            if (node->val == targetSum) {
                return {{node->val}};
            } else {
                return {};
            }
        }
        
    }
};

int main() {
    // root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    Solution solution;
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
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    int targetSum = 22;
    auto result = solution.pathSum(root, targetSum);
    for (const auto &i: result) {
        for (const auto &j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
