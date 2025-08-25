class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int i =0; 
        int j=0;
        bool flag = true;
        vector<int> ans;

        while (ans.size() != m*n){
            ans.push_back(mat[i][j]);

            if (flag){
                if (i!= 0 && j!= n-1){
                    i--;
                    j++;
                }
                else{
                    if (j == n-1) i++;
                    else j++;
                    flag = !flag;
                }
            }
            else {
                if (i!= m-1 && j!= 0){
                    i++;
                    j--;
                }
                else {
                    if (i == m-1) j++;
                    else i++;
                    flag = !flag;
                }
            }
        }
        return ans;
    }
};