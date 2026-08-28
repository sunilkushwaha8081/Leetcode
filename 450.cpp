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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL)
            return NULL;

        // Search in left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        // Search in right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // Node found
        else {

            // Case 1: No left child
            if (root->left == NULL)
                return root->right;

            // Case 2: No right child
            if (root->right == NULL)
                return root->left;

            // Case 3: Both children exist
            TreeNode* temp = root->right;

            // Find inorder successor
            while (temp->left != NULL)
                temp = temp->left;

            // Copy successor value
            root->val = temp->val;

            // Delete successor
            root->right = deleteNode(root->right, temp->val);
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

    // Create BST
    //
    //          5
    //        /   \
    //       3     7
    //      / \   / \
    //     2   4 6   8

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    cout << "Before deletion: ";
    inorder(root);

    Solution obj;

    // Delete 7
    root = obj.deleteNode(root, 7);

    cout << "\nAfter deletion: ";
    inorder(root);

    return 0;
}
