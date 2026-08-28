#include <iostream>
#include <vector>
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

    void convert(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;

        // Left
        convert(root->left, ans);

        // Root
        ans.push_back(root->val);

        // Right
        convert(root->right, ans);
    }

    int kthSmallest(TreeNode* root, int k) {

        vector<int> ans;

        convert(root, ans);

        return ans[k - 1];
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

    cout << "BST (Inorder): ";
    inorder(root);

    Solution obj;

    int k = 3;

    int result = obj.kthSmallest(root, k);

    cout << "\n" << k << "rd smallest element = " << result << endl;

    return 0;
}
