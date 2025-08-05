class Solution {
public:
    string reverseWords(string s) {
        string word;
        string ans;
        for(int i = s.size()-1 ; i>=0 ;i--){
            if (!word.empty() && s[i] == ' '){
                ans += word+" ";
                word = "";
            }
            
            if (s[i] != ' '){
                word = s[i]+ word;
            }
        }
        if (!word.empty()) ans += word + " ";
        ans.pop_back();
        return ans;
    }
};