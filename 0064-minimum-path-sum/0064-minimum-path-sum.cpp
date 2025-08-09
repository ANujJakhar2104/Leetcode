class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n,0);

        for(int i =0 ; i<m ;i++){
            vector<int> temp(n,0);
            for(int j =0 ; j < n;j++){
                if (i==0 && j==0) temp[j] = grid[i][j];
                else{
                    int up = 0;
                    if (i>0) up += dp[j];
                    else up = 1e9;

                    int down = 0;
                    if(j>0) down += temp[j-1];
                    else down = 1e9;

                    temp[j] = grid[i][j] + min(up ,down);
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
};