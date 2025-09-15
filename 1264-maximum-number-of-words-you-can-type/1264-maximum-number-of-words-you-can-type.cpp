class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;
        unordered_map<char,int> mp;
        for(auto& it : brokenLetters) mp[it] = 1;

        int i = 0;
        bool word = false; // word mila ya nhi
        bool found = false; // broken letter mila ya nhi
        while (i != text.size()){
            if (text[i] == ' '){
                if (word && !found) count++;
                word = false;
                found = false;
            }
            else{
                word = true;
                if (mp[text[i]] != 0)found = true;
            }
            i++;
        }
        if (word && !found) count++;
        return count;
    }
};
