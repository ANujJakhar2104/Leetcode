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
    int maxd;
    unordered_map<TreeNode* , int> mp;
private:
    TreeNode* LCA(TreeNode* node){
        if (node == NULL) return node;
        if (mp[node] == maxd) return node;
        TreeNode* l = LCA(node->left);
        TreeNode* r = LCA(node->right);

        if (l && r) return node;
        if (l) return l;
        return r;
    }

    void height(TreeNode* node , int ht){
        if (node == NULL) return;
        mp[node] = ht;
        maxd = max(maxd , ht);
        if (node->left) height(node->left, ht+1);
        if (node->right) height(node->right , ht+1);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        height(root,0);
        return LCA(root);
    }
};