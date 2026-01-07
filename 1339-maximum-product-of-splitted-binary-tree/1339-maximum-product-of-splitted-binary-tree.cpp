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
    const int mod = 1e9+7;
private:
    long long dfs(TreeNode* temp){
        if (temp == nullptr) return 0;
        temp->val += dfs(temp->right) + dfs(temp->left);
        return temp->val;
    }
public:
    int maxProduct(TreeNode* root) {
        long long total = dfs(root);
        long long ans= LLONG_MIN;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if (!temp) continue;

            long long curr = (total - temp->val) * temp->val;
            ans = max(ans , curr);

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        return ans%mod;
    }
};