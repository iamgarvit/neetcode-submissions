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
    void dfs(TreeNode* root, int maxVal, int& cnt) {
        if (!root)  return;
        maxVal = max(maxVal, root->val);
        if (maxVal <= root->val)    cnt++;

        dfs(root->left, maxVal, cnt);
        dfs(root->right, maxVal, cnt);
    }

    int goodNodes(TreeNode* root) {
        if (!root)  return 0;
        int cnt = 0;
        int maxVal = root->val;
        dfs(root, maxVal, cnt);
        return cnt;
    }
};
