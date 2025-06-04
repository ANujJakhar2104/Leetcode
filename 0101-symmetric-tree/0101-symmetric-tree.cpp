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
    void Traverse_left(TreeNode* node, list<string>& lt) {
        if (node == nullptr) {
            lt.push_back("null");
            return;
        }
        lt.push_back(to_string(node->val));
        Traverse_left(node->left, lt);
        Traverse_left(node->right, lt);
    }

    void Traverse_right(TreeNode* node, list<string>& rt) {
        if (node == nullptr) {
            rt.push_back("null");
            return;
        }
        rt.push_back(to_string(node->val));
        Traverse_right(node->right, rt);
        Traverse_right(node->left, rt);
    }

public:
    bool isSymmetric(TreeNode* root) {
        list<string> left;
        list<string> right;
        Traverse_left(root->left, left);
        Traverse_right(root->right, right);
        return left == right;
    }
};
