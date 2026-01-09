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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> temp;
        queue<pair<TreeNode* , pair<int,int>>> q;
        q.push({root , {0,0}});
        int min_idx = INT_MAX;
        int max_idx = INT_MIN;

        while (!q.empty()){
            int sz=q.size();
            while (sz--){
                int col = q.front().second.first;
                int row = q.front().second.second;
                TreeNode* node = q.front().first;
                q.pop();
                temp.push_back({col,row,node->val});
                min_idx = min(min_idx , col);
                max_idx = max(max_idx , col);

                if (node->left) q.push({node->left , {col-1 , row+1}});
                if (node->right) q.push({node->right , {col+1 , row+1}});
            }
        }

        vector<vector<int>> ans(max_idx-min_idx+1);
        sort(temp.begin() , temp.end());
        for(auto& [col ,row ,val]: temp){
            ans[col-min_idx].push_back(val);
        }
        return ans;
    }
};