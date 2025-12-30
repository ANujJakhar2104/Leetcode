// class Solution {
// public:
//     double largestSumOfAverages(vector<int>& nums, int k) {
//         sort(nums.begin() , nums.end());
//         int n = nums.size();
//         double sum = 0;
//         double temp = 0;
//         for(int i=0;i<n;i++){
//             if (i > n-k) sum += nums[i];
//             else temp += nums[i];
//         }
//         return sum + temp/(n-k+1);
//     }
// };
// this code for the case when we can take the elements at random


//this code is for the case when we can only take the adjacent subarrays
class Solution {
private:
    double solve(int idx , int k , vector<vector<double>>& dp , vector<int>&nums
    ,int n){
        if (idx >= n || k < 0) return 0;
        if (k == 0) return INT_MIN;
        if (dp[idx][k] != -1) return dp[idx][k];

        double ans = INT_MIN;
        double sum =0;
        for(int i=idx;i<n;i++){
            sum += nums[i];
            ans = max(ans
                ,(double)sum/(i-idx+1)+solve(i+1,k-1,dp,nums,n));
        }
        return dp[idx][k] = ans;
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        vector<vector<double>> dp(n , vector<double>(k+1 , -1));

        return solve(0, k , dp , nums,n);
    }
};

