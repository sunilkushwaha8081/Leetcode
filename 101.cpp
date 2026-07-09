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

    bool mirror(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;

        if (p && q)
            return (p->val == q->val) &&
                   mirror(p->left, q->right) &&
                   mirror(p->right, q->left);

        return false;
    }

    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;

        return mirror(root->left, root->right);
    }
};

int main() {
    /*
            1
          /   \
         2     2
        / \   / \
       3   4 4   3
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution obj;

    if (obj.isSymmetric(root))
        cout << "Tree is Symmetric";
    else
        cout << "Tree is Not Symmetric";

    return 0;
}