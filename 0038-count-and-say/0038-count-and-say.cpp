class Solution {
public:
    string countAndSay(int n) {
        int c = 1;
        string s = "1";
        if (n == 1)
            return s;
        while (c != n) {
            int count = 1;
            char num = s[0];
            string temp;
            for (int i = 1; i < s.size(); i++) {
                if (num == s[i])
                    count++;
                else {
                    temp = temp + to_string(count) + num;
                    num = s[i];
                    count = 1;
                }
            }
            temp = temp + to_string(count) + num;
            s = temp;
            c++;
        }
        return s;
    }
};