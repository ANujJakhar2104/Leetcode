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
    int maxLevelSum(TreeNode* root) {
        int index = 1;
        int ans = 1;
        int maxi = INT_MIN;

        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int sz = q.size();
            int sum = 0;
            for(int i=0;i<sz;i++){
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left != nullptr){
                    q.push(temp->left);
                }
                if (temp->right != nullptr){
                    q.push(temp->right);
                }
            }
            if (sum > maxi){
                ans = index;
                maxi = sum;
            }
            index++;
        }

        return ans;
    }
};