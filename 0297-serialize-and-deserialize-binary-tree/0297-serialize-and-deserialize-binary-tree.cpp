/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if (!ans.empty()) ans += ",";

            if(temp == nullptr) {
                ans += "nullptr";
                continue;
            }
            ans += to_string(temp->val);
            q.push(temp->left);
            q.push(temp->right);
        }

        return ans;
    }
    
    // Decodes your encoded data to tree.
    vector<string> split(string s, char delim = ',') {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            tokens.push_back(token);
        }
        return tokens;
    }
    TreeNode* deserialize(string data) {
        vector<string> ans = split(data);
        string s = ans[0];
        if (s == "nullptr") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
    
            string curr = ans[i];
            if (curr == "nullptr") {
                temp->left = nullptr;
            }else {
                TreeNode* lft = new TreeNode(stoi(curr));
                temp->left = lft;
                q.push(lft);
            }

            curr = ans[i+1];
            if (curr == "nullptr") {
                temp->right = nullptr;
            }else {
                TreeNode* rht = new TreeNode(stoi(curr));
                temp->right = rht;
                q.push(rht);
            }
            
            i += 2;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));