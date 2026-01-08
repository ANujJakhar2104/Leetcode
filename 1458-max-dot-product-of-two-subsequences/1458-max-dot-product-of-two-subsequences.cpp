class Solution {
    int n;
    int m;
private:
    long long solve(int i , int j,vector<int>& nums1, vector<int>&nums2,
            vector<vector<long long>>& dp){
        if (i == n || j == m) return LLONG_MIN;
        if (dp[i][j] != LLONG_MIN) return dp[i][j];

        long long tk = 1LL * nums1[i] * nums2[j];
        long long nxt = solve(i+1 , j+1 ,nums1,nums2,dp);
        if (nxt != LLONG_MIN) tk = max(tk , tk+nxt);

        long long tk1 = solve(i,j+1,nums1,nums2,dp);
        long long tk2 = solve(i+1,j,nums1,nums2,dp);

        return dp[i][j] = max({tk1 , tk2 , tk});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        vector<vector<long long>> dp(n,vector<long long>(m , LLONG_MIN));

        return (int)solve(0 ,0,nums1, nums2 , dp);
    }
};