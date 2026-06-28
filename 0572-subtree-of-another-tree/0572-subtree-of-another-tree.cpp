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
    bool check(TreeNode* node1 , TreeNode* node2){
        if (!node1 && !node2) return true;
        if (!node1 || !node2) return false;
        if (node1->val == node2->val){
            return check(node1->left , node2->left) && check(node1->right , node2->right);
        }

        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if (!root && !subroot) return true;
        if (!root || !subroot) return false;
        if(check(root , subroot)) return true;
        return isSubtree(root->left , subroot) || isSubtree(root->right , subroot);
    }
};