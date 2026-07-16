#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            vector<int> v;

            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();

                v.push_back(node->val);

                if (node->left != NULL)
                    q.push(node->left);

                if (node->right != NULL)
                    q.push(node->right);
            }

            ans.push_back(v);
        }

        return ans;
    }
};

int main() {
    // Creating the following tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<vector<int>> ans = obj.levelOrder(root);

    cout << "Level Order Traversal:\n";
    for (auto level : ans) {
        for (int x : level)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}