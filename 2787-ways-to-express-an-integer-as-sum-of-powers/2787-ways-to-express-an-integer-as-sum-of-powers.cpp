class Solution {
public:
    const int mod = 1e9+7;
    int numberOfWays(int n, int x) {
        vector<int> dp(n+1, 0);
        dp[0] =1;
        for(int i = 1 ; pow(i,x)<= n;i++){
            int curr = pow(i , x);
            for( int j = n ; j >= curr ; j--){
                dp[j] = (dp[j] + dp[j-curr])%mod;
            }
        }
        return dp[n]%mod;
    }
};