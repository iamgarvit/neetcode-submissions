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

class Codec {
public:

    // Encodes a tree to a single string.
    void helper_serialize(TreeNode* root, string& ans) {
        if (!root)  {
            ans = ans + " N";
            return;
        }

        ans += (" " + to_string(root->val));
        helper_serialize(root->left, ans);
        helper_serialize(root->right, ans);
    }

    string serialize(TreeNode* root) {
        string output = "";
        if (!root)  return output;
        helper_serialize(root, output);
        return output;
    }

    TreeNode* buildTree(vector<string>& nodes, int& ind) {
        if (nodes[ind] == "N")  {
            ind++;
            return nullptr;
        }
        if (ind >= nodes.size())    return nullptr;

        TreeNode* root = new TreeNode(stoi(nodes[ind]));
        ind++;
        root->left = buildTree(nodes, ind);
        root->right = buildTree(nodes, ind);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0)   return nullptr;
        stringstream ss(data);
        string word;

        vector<string> nodes;
        while (ss >> word) {
            nodes.push_back(word);
        }
        int ind = 0;
        TreeNode* ans = buildTree(nodes, ind);
        return ans;
    }
};
