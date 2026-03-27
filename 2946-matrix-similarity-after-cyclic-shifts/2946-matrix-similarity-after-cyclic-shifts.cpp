class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> temp(n , vector<int>(m , 0));
        k = k%m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (i%2 ==0){
                    temp[i][j] = mat[i][(j+k)%m];
                }
                else {
                    temp[i][j] = mat[i][(j-k+m)%m];
                }
            }
        }
        return temp == mat;
    }
};