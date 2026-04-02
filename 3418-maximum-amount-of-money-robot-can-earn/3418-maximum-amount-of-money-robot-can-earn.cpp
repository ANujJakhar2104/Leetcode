class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    int solve(int i, int j, vector<vector<int>>& coins, int k) {
        if (i == m-1 && j == n-1) {
            if (coins[i][j] >= 0)
                return dp[i][j][k] = coins[i][j];
            if (k < 2)
                return dp[i][j][k] = 0;
            return dp[i][j][k] = coins[i][j];
        }   

        if (dp[i][j][k] != INT_MIN)
            return dp[i][j][k];

        int curr_val = coins[i][j];
        if (curr_val < 0 && k < 2){
            int take = INT_MIN;
            if (i+1 <m) take = max(take , solve(i+1 , j , coins , k+1));
            if (j+1 <n) take = max(take , solve(i , j+1 , coins , k+1));

            int ntake = INT_MIN;
            if (i+1 <m) ntake = max(ntake , solve(i+1 , j , coins , k));
            if (j+1 <n) ntake = max(ntake , solve(i , j+1 , coins , k));
            
            return dp[i][j][k] = max(take , coins[i][j] + ntake);
        }

        int temp = INT_MIN;
        if (i+1 <m) temp = max(temp , solve(i+1 , j , coins , k));
        if (j+1 <n) temp = max(temp , solve(i , j+1 , coins , k));
        return dp[i][j][k] = curr_val + temp;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        solve(0, 0, coins, 0);
        return dp[0][0][0];
    }
};