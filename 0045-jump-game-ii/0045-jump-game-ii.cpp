class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums[0] == 0)
            return 0;
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0 && dp[i] != INT_MAX) {
                for (int step = nums[i]; step >= 1; step--) {
                    if (i + step < n) {
                        dp[i + step] = min(dp[i + step], dp[i] + 1);
                    }
                    if (dp[n - 1] != INT_MAX)
                        return dp[n - 1];
                }

            } else {
                continue;
            }
        }
        return dp[n - 1];
    }
};
