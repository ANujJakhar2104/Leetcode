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
    int MaxSum = INT_MIN;
private:
    int sum(TreeNode* node){
        if (node == NULL) return 0;
        int left = max(0 , sum(node->left));
        int right = max(0 , sum(node->right));

        MaxSum = max(MaxSum , node->val + left + right);

        return node->val + max(left , right);
    }
public:
    int maxPathSum(TreeNode* root) {
        sum(root);
        return MaxSum;
    }
};