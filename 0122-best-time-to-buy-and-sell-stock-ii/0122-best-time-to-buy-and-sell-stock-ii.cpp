class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<vector<long>> dp(n+1, vector<long>(2, 0));
        dp[n][0] = 0;
        dp[n][1] = INT_MIN;

        for (int i = n-1; i >= 0; i--) {
            dp[i][0] = max(dp[i+1][0], -arr[i] + dp[i+1][1]); // buy kr lia tho minus
            dp[i][1] = max(dp[i+1][1], arr[i] + dp[i+1][0]); // sell krna sai 
        }

        return dp[0][0];
    }
};
