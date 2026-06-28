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
    int ans = 0;
    void solve(TreeNode* node , int temp){
        if (!node) {
            ans = max(ans , temp);
            return;
        }
        solve(node->left , temp+1);
        solve(node->right , temp+1);
    }
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        solve(root , 0);
        return ans;
    }
};