class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;
        unordered_map<char,int> mp;
        for (auto& it : brokenLetters) mp[it] = 1;

        bool word = false;   // current word exists?
        bool found = false;  // broken letter found in current

        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {  
                if (word && !found) count++;
                word = false;
                found = false;
            }
            else {
                word = true;
                if (mp[text[i]] != 0) found = true;
            }
        }
        return count;
    }
};
