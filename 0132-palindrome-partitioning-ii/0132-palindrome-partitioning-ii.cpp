class Solution {
private:
    bool check(int st,int ed,string& s){
        while (st <= ed){
            if (s[st] != s[ed]) return false;
            else {
                st++;
                ed--;
            }
        }
        return true;
    }
    int solve(int i,int j , vector<vector<int>>& dp, string& s){
        if (i > j) return 0;
        if (check(i,j,s)) return dp[i][j] = 0;
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int idx =i; idx<j ;idx++){
            if (check(i,idx,s)){
                int part = 1 + solve(idx+1,j,dp,s);
                mini = min(mini , part);
            }
        }
        return dp[i][j] = mini;
    }
public:
    int minCut(string s) {
        int n = s.size();
        if (n == 1) return 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,dp,s);
    }
};