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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        map<int,int> mp;
        queue<TreeNode*> q;
        q.push(root);
        int curr = 0;

        while(!q.empty()){
            int sz = q.size();
            while (sz--){
                TreeNode* node = q.front();
                q.pop();

                mp[curr] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            curr++;
        }
        vector<int> ans;
        for(auto& it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};