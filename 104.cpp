#include <iostream>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    int height(TreeNode* root) {
        if (!root)
            return 0;

        int leftnode = height(root->left);
        int rightnode = height(root->right);

        return 1 + max(leftnode, rightnode);
    }

    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        int leftheight = height(root->left);
        int rightheight = height(root->right);

        return 1 + max(leftheight, rightheight);
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5

    Height = 3
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    cout << "Maximum Depth = " << obj.maxDepth(root);

    return 0;
}