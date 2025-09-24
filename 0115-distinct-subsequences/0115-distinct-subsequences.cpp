class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double> dp(m+1, 0);
        dp[m] = 1;
        for (int i = n-1; i >= 0; i--) {
            vector<double> next = dp;
            for (int j = m-1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    next[j] += dp[j+1];
                }
            }
            dp = next;
        }
        return (int)dp[0];
    }
};
