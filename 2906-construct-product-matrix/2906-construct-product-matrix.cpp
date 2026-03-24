class Solution {
public:
    const int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> pr_front = grid;
        vector<vector<int>> pr_back = grid;
        vector<long long> rw(n , 1);
        for(int i=0;i<n;i++){
            int curr = grid[i][0];
            for(int j=1;j<m;j++){
                curr = (1LL * curr * grid[i][j]) % mod;
                pr_front[i][j] = (1LL * pr_front[i][j]*pr_front[i][j-1])%mod;

                pr_back[i][m-j-1] = (1LL * pr_back[i][m-j-1]*pr_back[i][m-j])%mod;
            }
            rw[i] = curr;
        }

        vector<long long> rw_front = rw;
        vector<long long> rw_back = rw;
        for(int i=1;i<n;i++){
            rw_front[i] = (1LL * rw_front[i] * rw_front[i-1])%mod;

            rw_back[n-i-1] = (1LL * rw_back[n-i-1] * rw_back[n-i])%mod;
        }

        vector<vector<int>> ans(n ,vector<int>(m ,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int left = (j > 0) ? pr_front[i][j-1] : 1;
                int right = (j < m-1) ? pr_back[i][j+1] : 1;
                int up = (i > 0) ? rw_front[i-1] :1;
                int down = (i < n-1) ? rw_back[i+1] : 1;
                ans[i][j] = (((1LL * left * right) % mod * up) % mod * down) % mod;
            }
        }

        return ans;
    }
};