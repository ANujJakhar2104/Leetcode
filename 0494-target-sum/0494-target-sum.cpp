// class Solution {
// public:
//     int solve(int idx, int target, int sum, int offset,
//               vector<vector<int>>& dp, vector<int>& nums) {

//         if (idx == 0) {
//             int cnt = 0;
//             if ((sum + nums[0]) == target) cnt++;
//             if ((sum - nums[0]) == target) cnt++;
//             return cnt;
//         }

//         if (dp[idx][sum + offset] != -1)
//             return dp[idx][sum + offset];

//         int pos = solve(idx - 1, target, sum + nums[idx], offset, dp, nums);
//         int neg = solve(idx - 1, target, sum - nums[idx], offset, dp, nums);

//         return dp[idx][sum + offset] = pos + neg;
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int total = 0;
//         for (int x : nums) total += x;

//         int offset = total;
//         vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));

//         return solve(n - 1, target, 0, offset, dp, nums);
//     }
// };  this code is for taking +ve or -ve for each element and add there solutions using offset as there can also a negative sum.


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto& it : nums) sum += it;

        if ((sum - target) < 0 || ((sum - target) % 2 != 0)) return 0;

        int goal = (sum - target) / 2;

        vector<int> prev(goal + 1, 0);
        prev[0] = 1;

        if (nums[0] <= goal) prev[nums[0]] += 1;

        for (int i = 1; i < nums.size(); i++) {
            vector<int> curr(goal + 1, 0);
            curr[0] = 1;

            for (int k = 0; k <= goal; k++) {
                int ntake = prev[k];
                int take = 0;
                if (nums[i] <= k) take = prev[k - nums[i]];

                curr[k] = take + ntake;
            }
            prev = curr;
        }

        return prev[goal];
    }
};


