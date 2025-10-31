class Solution {
public:
    string arrangeWords(string text) {
        int count = 0;
        unordered_map<int, vector<string>> mp;
        string temp;

        text[0] = tolower(text[0]);
        
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                mp[count].push_back(temp);
                count = 0;
                temp.clear();
                continue;
            }else{
                count++;
                temp += text[i];
            }
        }
        mp[count].push_back(temp);
        vector<int> keys;
        for (auto& it : mp) keys.push_back(it.first);
        sort(keys.begin(), keys.end());
        string ans;
        for (int k : keys) {
            for (string s : mp[k]) {
                ans += s;
                ans += ' ';
            }
        }
        if (!ans.empty()) ans.pop_back();
        if (!ans.empty()) ans[0] = toupper(ans[0]);
        return ans;
    }
};