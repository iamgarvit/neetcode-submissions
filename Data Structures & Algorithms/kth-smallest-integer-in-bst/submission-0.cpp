/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void inorder_traversal(TreeNode* root, vector<int>& store, int k) {
        if (!root)  return;
        if (store.size() == k)  return;

        inorder_traversal(root->left, store, k);
        store.push_back(root->val);
        inorder_traversal(root->right, store, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> store;
        inorder_traversal(root, store, k);
        return store[k - 1];
    }
};
