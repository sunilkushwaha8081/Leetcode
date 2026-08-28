#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // If tree/subtree is empty
        if (root == NULL) {
            return new TreeNode(val);
        }

        // Go to left subtree
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }

        // Go to right subtree
        else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};

// Inorder traversal
void inorder(TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    // Create initial BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    // Insert values
    Solution obj;

    root = obj.insertIntoBST(root, 8);
    root = obj.insertIntoBST(root, 2);
    root = obj.insertIntoBST(root, 6);

    // Print BST
    cout << "Inorder traversal: ";
    inorder(root);

    return 0;
}
