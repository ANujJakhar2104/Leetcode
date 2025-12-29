class Solution {
private:
    int solve(int idx , int buy ,int n,vector<vector<int>>& dp
    ,vector<int>& prices){
        if (idx >= n) return 0;
        if (dp[idx][buy] != -1) return dp[idx][buy];
        int profit=0;
        if (buy){
            profit = max((-prices[idx]+solve(idx+1,0,n,dp,prices))
            , solve(idx+1,1,n,dp,prices));
        }
        else{
            profit = max((prices[idx]+solve(idx+2,1,n,dp,prices))
            ,solve(idx+1,0,n,dp,prices));
        }

        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==1) return 0;

        vector<vector<int>> dp(n , vector<int>(2,-1));
        return solve(0, 1 ,n,dp,prices);
    }
};