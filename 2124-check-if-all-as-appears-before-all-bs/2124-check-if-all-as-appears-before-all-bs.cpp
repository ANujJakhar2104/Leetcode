class Solution {
public:
    bool checkString(string s) {
        bool found = false;
        for(char x : s){
            if (x == 'b') found = true;
            if (found && x == 'a') return false; 
        }
        return true;
    }
};