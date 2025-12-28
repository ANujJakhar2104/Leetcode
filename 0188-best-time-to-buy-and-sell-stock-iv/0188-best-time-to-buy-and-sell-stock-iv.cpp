// class Solution {
// private:
//     int solve(int idx, int buy, int k, vector<vector<vector<int>>>& dp,
//               vector<int>& prices, int n) {

//         if (idx == n || k == 0)
//             return 0;

//         if (dp[idx][buy][k] != -1)
//             return dp[idx][buy][k];

//         int profit;
//         if (buy) {
//             profit = max(-prices[idx] + solve(idx+1,0,k,dp,prices,n),
//                          solve(idx + 1, 1, k, dp, prices, n));
//         } else {
//             profit = max(prices[idx]+solve(idx+1,1,k-1,dp,prices,n),
//                          solve(idx+1,0,k,dp,prices,n));
//         }

//         return dp[idx][buy][k] = profit;
//     }

// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();

//         vector<vector<vector<int>>> dp(
//             n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

//         return solve(0, 1, k, dp, prices, n);
//     }
// };


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(2, vector<int>(k + 1, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            vector<vector<int>> new_dp(2, vector<int>(k + 1, 0));
            for (int buy = 0; buy < 2; buy++) {
                for (int count = 1; count <= k; count++) {
                    if (buy) {
                        new_dp[buy][count] = max(-prices[idx]+dp[0][count]
                            ,dp[1][count]
                        );
                    } else {
                        new_dp[buy][count] = max(prices[idx]+dp[1][count-1]
                            ,dp[0][count]);
                    }
                }
            }
            dp = new_dp;
        }

        return dp[1][k];
    }
};
