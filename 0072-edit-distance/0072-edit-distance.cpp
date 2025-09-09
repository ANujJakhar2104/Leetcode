// simple recursion
// class Solution {
// public:
//     int find(int i, int j, string s1, string s2) {
//         if (j == 0)
//             return i;
//         if (i == 0)
//             return j;

//         if (s1[i-1] == s2[j-1])
//             return find(i - 1, j - 1, s1, s2);

//         return 1 + min({find(i, j - 1, s1, s2), find(i - 1, j, s1, s2),
//                         find(i - 1, j - 1, s1, s2)});
//     }
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();

//         return find(n, m, word1, word2);
//     }
// };

// recursion with memoization
// class Solution {
// public:
//     int find(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
//         if (j == 0)
//             return i;
//         if (i == 0)
//             return j;
//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (s1[i - 1] == s2[j - 1])
//             return find(i - 1, j - 1, s1, s2, dp);

//         return dp[i][j] = 1 + min({find(i, j - 1, s1, s2, dp),
//                                            find(i - 1, j, s1, s2, dp),
//                                            find(i - 1, j - 1, s1, s2, dp)});
//     }
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();

//         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
//         for (int i = 1; i <= n; i++)
//             dp[i][0] = i;
//         for (int j = 1; j <= m; j++)
//             dp[0][j] = j;
//         return find(n, m, word1, word2, dp);
//     }
// };

// tabulation with space optimization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> dp(m + 1);
        for (int i = 0; i <= m; i++) dp[i] = i;

        for (int i = 1; i <= n; i++) {
            vector<int> new_dp(m + 1);
            new_dp[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) new_dp[j] = dp[j-1];
                else new_dp[j] = 1 + min({dp[j] , dp[j-1] , new_dp[j-1]});
            }
            dp = new_dp;
        }

        return dp[m];
    }
};