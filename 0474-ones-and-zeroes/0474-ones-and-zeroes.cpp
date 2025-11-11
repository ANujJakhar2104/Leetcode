class Solution {
public:
    int find(vector<string>& strs, int m, int n, int idx, vector<vector<vector<int>>>& dp) {
        if (idx < 0) return 0;
        if (dp[idx][m][n] != -1) return dp[idx][m][n];

        int zr = count(strs[idx].begin(), strs[idx].end(), '0');
        int one = strs[idx].size() - zr;

        int ntake = find(strs, m, n, idx - 1, dp);

        int take = 0;
        if (zr <= m && one <= n) {
            take = 1 + find(strs, m - zr, n - one, idx - 1, dp);
        }

        return dp[idx][m][n] = max(take, ntake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return find(strs, m, n, sz - 1, dp);
    }
};