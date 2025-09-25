class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        if (tri.size() == 1) return tri[0][0];
        int ans = INT_MAX;
        int n = tri.size();
        for(int i = 1 ; i < n ; i++){
            int curr_n = tri[i].size();
            for(int j = 0 ; j < curr_n ; j++){
                if (j == 0) {
                    tri[i][j] += tri[i-1][j];
                }
                else if (j==(curr_n - 1)) {
                    tri[i][j] += tri[i-1][j-1];
                }
                else {
                    tri[i][j] += min(tri[i-1][j] , tri[i-1][j-1]);
                }

                if (i == n-1) ans = min(ans , tri[i][j]);
            }
        }
        return ans;
    }
};