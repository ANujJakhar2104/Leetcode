class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;
        int n = exp.size();
        for(int i=0 ;i <n ;i++){
            if (exp[i] ==',') continue;

            if (exp[i] == ')'){
                int t = 0;
                int f = 0;
                while (st.top() != '('){
                    if (st.top() == 't') t++;
                    else f++;
                    st.pop();
                }
                bool ans;
                st.pop();
                
                char op = st.top();
                st.pop();

                if (op == '|') ans = t > 0 ? 1:0;
                else if (op == '&') ans = f>0 ? 0:1;
                else ans = f>0 ? 1:0;

                st.push(ans ? 't' : 'f');
            }
            else {
                st.push(exp[i]);
            }
        }

        return st.top() == 't';
    }
};