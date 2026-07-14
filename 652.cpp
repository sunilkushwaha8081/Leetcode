#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    unordered_map<string, int> mp;
    vector<TreeNode*> ans;

    string dfs(TreeNode* root) {
        if (root == nullptr)
            return "#";

        string s = to_string(root->val) + "," +
                   dfs(root->left) + "," +
                   dfs(root->right);

        mp[s]++;

        if (mp[s] == 2)
            ans.push_back(root);

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

// Example usage
int main() {
    /*
            1
           / \
          2   3
         /   / \
        4   2   4
           /
          4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);

    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);

    root->right->right = new TreeNode(4);

    Solution obj;
    vector<TreeNode*> duplicates = obj.findDuplicateSubtrees(root);

    cout << "Duplicate subtree roots: ";
    for (TreeNode* node : duplicates) {
        cout << node->val << " ";
    }
    cout << endl;

    return 0;
}