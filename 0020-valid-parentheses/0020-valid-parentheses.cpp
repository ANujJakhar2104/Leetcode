class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if (ch == '(' || ch == '[' || ch == '{' || st.empty()){
                st.push(ch);
            }else{
                char tp = st.top();
                if ((ch == ')' && tp == '(') || (ch == ']' && tp == '[') 
                || (ch == '}' && tp == '{')) {
                    st.pop();
                }
                else return false;
            }
        }

        if (st.empty()) return true;
        return false;
    }
};