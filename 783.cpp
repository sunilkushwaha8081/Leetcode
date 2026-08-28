#include <iostream>
#include <climits>
#include <algorithm>
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
    int ans = INT_MAX;
    TreeNode* prev = NULL;

    void height(TreeNode* root) {
        if (root == NULL)
            return;

        // Left
        height(root->left);

        // Process current node
        if (prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }

        prev = root;

        // Right
        height(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        height(root);
        return ans;
    }
};

int main() {

    // Create BST
    //
    //        4
    //       / \
    //      2   6
    //     / \   \
    //    1   3   7

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->right = new TreeNode(7);

    Solution obj;

    int result = obj.minDiffInBST(root);

    cout << "Minimum difference = " << result << endl;

    return 0;
}
