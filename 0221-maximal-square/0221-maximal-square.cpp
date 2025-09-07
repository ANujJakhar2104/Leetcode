class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        vector<int> dp(m);

        for (int i = 0; i < n; i++) {
            vector<int> new_dp(m);
            new_dp[0] = matrix[i][0]-'0';
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        new_dp[j] = 1;
                    } else {
                        new_dp[j] = 1 + min({dp[j], new_dp[j-1], dp[j-1]});
                    }
                    ans = max(ans, new_dp[j]);
                }
            }
            dp = new_dp;
        }

        return ans * ans;
    }
};

