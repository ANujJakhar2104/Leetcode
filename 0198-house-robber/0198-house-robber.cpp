class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int i , int prev , vector<int>& nums){
        if (i == n) return 0;
        if (dp[i][prev+1] != -1) return dp[i][prev+1];
        int take = 0;
        if (prev < i-1 || prev == -1){
            take = nums[i]+solve(i+1,i,nums);
        }
        int ntake = solve(i+1 ,prev ,nums);
        return dp[i][prev+1] = max(take , ntake);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.resize(n , vector<int>(n+1, -1));
        int ans = 0;
        return solve(0,-1,nums);
    }
};