class Solution {
private:
string word(stack<char>& a){
    string x;
    while (!a.empty()){
        x = a.top() + x;
        a.pop();
    }
    return x;
}
public:
    string reverseWords(string s) {
        stack<char> a;
        string ans;

       for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                a.push(s[i]);
            } else if (!a.empty()) {
                string m = word(a);
                ans = m + " " +ans;
            }
        }

        if (!a.empty()) {
            string m = word(a);
            ans = m + " " + ans;
        }

        ans.pop_back();

        return ans;
    }
};