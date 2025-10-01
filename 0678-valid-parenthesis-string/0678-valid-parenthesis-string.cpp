class Solution {
public:
    bool checkValidString(string s) {
        // int pr = 0;
        // stack<char> st;
        // int cnt = 0;
        int maxi = 0 , mini = 0;
        for(int i =0 ; i < s.size() ; i++){
            if (s[i] == '('){
                maxi += 1;
                mini += 1;
            }
            else if (s[i] == ')'){
                mini -= 1;
                maxi -= 1;
            }
            else {
                mini -= 1;
                maxi += 1;
            }
            if (mini < 0) mini = 0;
            if (maxi < 0) return false;
        }
        return mini == 0;
        // if (st.empty()) return true;

        // while (!st.empty()){
        //     if (st.top == ')') inv += 1;

        // }
        
    }
};