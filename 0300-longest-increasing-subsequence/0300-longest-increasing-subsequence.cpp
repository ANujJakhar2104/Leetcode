class Solution {
private:
    int solve(int idx,int prev,vector<vector<int>>&dp,vector<int>&nums){
        if (idx == nums.size()) return 0;
        if (dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int ntake = solve(idx+1,prev,dp,nums);

        int take =0;
        if (prev == -1 || nums[idx] > nums[prev]){
            take = 1 + solve(idx+1,idx,dp,nums);
        }
        
        return dp[idx][prev+1] = max(take ,ntake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1,-1));
        return solve(0,-1,dp,nums);
    }
};