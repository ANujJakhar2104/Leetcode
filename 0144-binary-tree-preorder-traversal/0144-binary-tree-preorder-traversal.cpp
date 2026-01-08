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
    vector<int> ans;
private:
    void preorder(TreeNode* node){
        ans.push_back(node->val);
        if (node->left) preorder(node->left);
        if (node->right) preorder(node->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        preorder(root);
        return ans;
    }
};