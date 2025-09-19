class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<int> dp(n+1 ,0);
        string t = s;  
        reverse(t.begin(), t.end());

        for(int i = 1; i <= n; i++) {
            vector<int> new_dp(n+1 , 0);
            for(int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) {
                    new_dp[j] = 1 + dp[j-1];
                } else {
                    new_dp[j] = max(dp[j], new_dp[j-1]);
                }
            }
            dp = new_dp;
        }
        return n-dp[n];
    }
};