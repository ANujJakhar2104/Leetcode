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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        unordered_map<TreeNode* , TreeNode*> mp;
        set<TreeNode*> last;

        while (!q.empty()){
            int sz = q.size();
            last.clear();

            while (sz--){
                TreeNode* temp = q.front();
                q.pop();
                last.insert(temp);

                if (temp->left) {
                    mp[temp->left] = temp;
                    q.push(temp->left);
                }

                if (temp->right) {
                    mp[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }

        while (last.size() > 1){
            set<TreeNode*> next;
            for(TreeNode* node : last){
                next.insert(mp[node]);
            }
            last = next;
        }
        return *last.begin();
    }
};