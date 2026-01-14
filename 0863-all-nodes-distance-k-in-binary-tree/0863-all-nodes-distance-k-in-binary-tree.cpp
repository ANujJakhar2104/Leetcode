/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode* tar,TreeNode* parent, int k , vector<int>& ans,
        unordered_map<TreeNode*, vector<TreeNode*>>& adj){
        if (k == 0) {
            ans.push_back(tar->val);
            return;
        }
        for(TreeNode* a : adj[tar]){
            if (a == parent) continue;
            solve(a ,tar,k-1,ans,adj);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) return {target->val};
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if (node->left){
                q.push(node->left);
                adj[node].push_back(node->left);
                adj[node->left].push_back(node);
            }

            if (node->right){
                q.push(node->right);
                adj[node].push_back(node->right);
                adj[node->right].push_back(node);
            }
        }

        vector<int> ans;
        for(TreeNode* a : adj[target]){
            solve(a,target,k-1,ans,adj);
        }
        return ans;
    }
};