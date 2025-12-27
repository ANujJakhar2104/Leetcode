// class Solution {
// private:
//     int solve(int idx , int buy , int count , vector<int>&prices ,int n,
//         vector<vector<vector<int>>>& dp) {

//         if (idx == n || count == 0)
//             return 0;

//         if (dp[idx][buy][count] != -1)
//             return dp[idx][buy][count];

//         int profit;
//         if (buy) {
//             profit =max(-prices[idx]+solve(idx+1,0,count,prices,n,dp)
//                     ,solve(idx+1,1,count,prices,n,dp));
//         } else {
//             profit = max(prices[idx] + solve(idx+1,1,count-1,prices,n,dp)
//                         ,solve(idx+1,0,count,prices,n,dp));
//         }

//         return dp[idx][buy][count] = profit;
//     }

// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(
//             n, vector<vector<int>>(2, vector<int>(3, -1)));

//         return solve(0,1,2,prices,n,dp);
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0))
        );

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int count = 1; count < 3; count++) {
                    int profit;
                    if (buy) {
                        profit = max(
                            -prices[idx] + dp[idx + 1][0][count],
                            dp[idx + 1][1][count]
                        );
                    } else {
                        profit = max(
                            prices[idx] + dp[idx + 1][1][count - 1],
                            dp[idx + 1][0][count]
                        );
                    }
                    dp[idx][buy][count] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};
