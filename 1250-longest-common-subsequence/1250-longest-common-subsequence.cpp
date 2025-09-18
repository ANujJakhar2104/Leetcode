// class Solution {
// public:
//     int n, m;
//     vector<vector<int>> dp;

//     int find(int idx1, int idx2, string &text1, string &text2) {
//         if (idx1 == 0 || idx2 == 0) return 0;
//         if (dp[idx1][idx2] != -1) return dp[idx1][idx2];

//         if (text1[idx1-1] == text2[idx2-1]) {
//             return dp[idx1][idx2] = 1 + find(idx1 - 1, idx2 - 1, text1, text2);
//         }
//         return dp[idx1][idx2] = max(find(idx1 - 1, idx2, text1, text2),
//                                     find(idx1, idx2 - 1, text1, text2));
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         n = text1.size();
//         m = text2.size();
//         dp.assign(n+1, vector<int>(m+1, -1));
//         return find(n, m, text1, text2);
//     }
// };



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> dp(n+1 ,0);

        for(int i=1;i<=m;i++){
            vector<int> new_dp(n+1 , 0);
            for(int j = 1 ; j <=n ;j++){
                if (text1[j-1] == text2[i-1]) new_dp[j] = 1 + dp[j-1];
                else {
                    new_dp[j] = max(dp[j] , new_dp[j-1]);
                }
            }
            dp = new_dp;
        }

        return dp[n];
    }
};