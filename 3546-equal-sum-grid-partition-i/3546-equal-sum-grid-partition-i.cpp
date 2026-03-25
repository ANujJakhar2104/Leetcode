class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> row(n*m , 0);
        vector<long long> col(n*m , 0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i*m + j] = grid[i][j];
                col[j*n + i] = grid[i][j];
            }
        }

        vector<long long> row_pre = row;
        vector<long long> row_suff = row;
        vector<long long> col_pre = col;
        vector<long long> col_suff = col;

        for(int i=1;i<n*m;i++){
            row_pre[i] += row_pre[i-1];
            col_pre[i] += col_pre[i-1];

            row_suff[n*m - i -1] += row_suff[n*m - i];
            col_suff[n*m - i -1] += col_suff[n*m - i];
        }

        for(int i=m-1;i<n*m-1;i+=m){
            if(row_pre[i] == row_suff[i+1]) return true;
        }

        for(int i=n-1;i<n*m-1;i+=n){
            if (col_pre[i] == col_suff[i+1]) return true;
        }

        return false;
    }
};