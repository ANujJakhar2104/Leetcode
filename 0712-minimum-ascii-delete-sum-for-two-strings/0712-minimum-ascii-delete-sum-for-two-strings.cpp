class Solution {
    int n, m;

private:
    int solve(int i, int j, vector<vector<int>>& dp, 
        string &s1, string &s2) {
        if (i == n) {
            int sum = 0;
            for (int k = j; k < m; k++)
                sum += s2[k];
            return dp[i][j] = sum;
        }

        if (j == m) {
            int sum = 0;
            for (int k = i; k < n; k++)
                sum += s1[k];
            return dp[i][j] = sum;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            dp[i][j] = solve(i+1,j+1,dp,s1,s2);
        } else {
            dp[i][j] = min(s1[i] + solve(i+1,j,dp,s1,s2)
                    ,s2[j] + solve(i,j+1,dp,s1,s2));
        }

        return dp[i][j];
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, dp, s1, s2);
    }
};
