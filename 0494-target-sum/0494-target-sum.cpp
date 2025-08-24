class Solution {
public:
    int solve(int idx, int target, int sum, int offset,
              vector<vector<int>>& dp, vector<int>& nums) {

        if (idx == 0) {
            int cnt = 0;
            if ((sum + nums[0]) == target) cnt++;
            if ((sum - nums[0]) == target) cnt++;
            return cnt;
        }

        if (dp[idx][sum + offset] != -1)
            return dp[idx][sum + offset];

        int pos = solve(idx - 1, target, sum + nums[idx], offset, dp, nums);
        int neg = solve(idx - 1, target, sum - nums[idx], offset, dp, nums);

        return dp[idx][sum + offset] = pos + neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for (int x : nums) total += x;

        int offset = total;
        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));

        return solve(n - 1, target, 0, offset, dp, nums);
    }
};
