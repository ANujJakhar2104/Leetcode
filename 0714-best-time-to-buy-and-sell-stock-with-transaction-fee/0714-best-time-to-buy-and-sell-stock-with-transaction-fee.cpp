class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<int> dp(n,0);
        // for(int i = n-1 ;i>=0;i--){
        //     vector<int> new_dp(n,0);
        //     for(int buy =0;buy<=1 ; buy++){
        //         if (buy){
        //             new_dp[i] = max((-prices[i] + dp[i]),
        //             dp[i]);
        //         }
        //         else {
        //             new_dp[i] = max((prices[i] - fee + dp[i]),
        //             dp[i]);
        //         }
        //     }
        //     dp = new_dp;
        // }

        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i = n-1;i>=0;i--){
            dp[i][1] = max((-prices[i] + dp[i+1][0])
                ,dp[i+1][1]);

            dp[i][0] = max((prices[i] - fee + dp[i+1][1])
                ,dp[i+1][0]);
        }

        return dp[0][1];
    }
};