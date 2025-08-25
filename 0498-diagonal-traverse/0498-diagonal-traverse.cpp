class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m+n-1);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> val;
        for(int i=0; i < m+n-1; i++){
            if (i%2 ==0) reverse(ans[i].begin(), ans[i].end());
            for(int x : ans[i]) {
                val.push_back(x);
            }
        }

        return val;
    }
};
