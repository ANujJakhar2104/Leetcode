class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> dp(n+1 , 0);

        for(int i=1; i<=m ;i++){
            vector<int> new_dp(n+1 , 0);
            for(int j=1 ; j<=n ;j++){
                if (s[j-1] == t[i-1]){
                    new_dp[j] = 1 + dp[j-1];
                }
                else {
                    new_dp[j] = max(dp[j] , new_dp[j-1]);
                }
            }
            dp = new_dp;
        }
        return m + n - 2*dp[n];
    }
};