class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        string vowels = "aeiouAEIOU";
        int vo = 0 , cons = 0;
        
        for(char a : word){
            if (isalpha(a)){
                if (vowels.find(a) != string::npos) vo++;
                else cons++;
            }
            else if (!isdigit(a)){
            return false;
            }
        }
    return vo >=1 && cons >=1;
    }
};