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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool rev = false;

        while (!q.empty()){
            int sz = q.size();
            vector<int> curr;
            while (sz--){
                TreeNode* node = q.front();
                q.pop();
                curr.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (rev) reverse(curr.begin() , curr.end());
            ans.push_back(curr);
            rev = !rev;
        }    
        return ans;
    }
};



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
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if (!root) return ans;
//         deque<TreeNode*> dq;
//         dq.push_back(root);
//         bool reverse = false;

//         while (!dq.empty()){
//             deque<TreeNode*> new_dq;
//             vector<int> curr;
//             while (!dq.empty()){
//                 TreeNode* node;
//                 if (reverse){
//                     node = dq.back();
//                     dq.pop_back();
//                 }
//                 else{
//                     node = dq.front();
//                     dq.pop_front();
//                 }
//                 curr.push_back(node->val);
//                 if (!reverse) {
//                     if (node->left)  new_dq.push_back(node->left);
//                     if (node->right) new_dq.push_back(node->right);
//                 } else {
//                     if (node->right) new_dq.push_back(node->right);
//                     if (node->left)  new_dq.push_back(node->left);
//                 }
//             }
//             dq = new_dq;
//             ans.push_back(curr);
//             reverse = !reverse;
//         }

//         return ans;
//     }
// };