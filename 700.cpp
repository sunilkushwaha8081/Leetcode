#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val)
            return root;

        if (root->val < val)
            return searchBST(root->right, val);

        if (root->val > val)
            return searchBST(root->left, val);

        return nullptr;
    }
};

int main() {
    // Creating BST
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;

    int val = 2;
    TreeNode* result = obj.searchBST(root, val);

    if (result != nullptr)
        cout << "Value found: " << result->val << endl;
    else
        cout << "Value not found" << endl;

    return 0;
}
