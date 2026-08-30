#include <bits/stdc++.h>
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
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;

        // Dono BST ke elements ek vector me
        inorder(root1, ans);
        inorder(root2, ans);

        // Sort the vector
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    // BST 1
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    // BST 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    Solution obj;

    vector<int> result = obj.getAllElements(root1, root2);

    // Print result
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
