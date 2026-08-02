class Solution {
public:
    long long solve(int i, int j, vector<int>& nums, vector<vector<long long>>& memo) {
        if (i > j) return 0;
        if (memo[i][j] != LLONG_MIN) return memo[i][j];

        long long take_i = nums[i] - solve(i+1, j, nums, memo);
        long long take_j = nums[j] - solve(i, j-1, nums, memo);

        return memo[i][j] = max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> memo(n, vector<long long>(n, LLONG_MIN));
        return solve(0, n-1, nums, memo) >= 0;
    }
};