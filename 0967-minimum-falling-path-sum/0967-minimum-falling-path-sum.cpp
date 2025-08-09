class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int curr = matrix[i + 1][j];
                if (j > 0)
                    curr = min(curr, matrix[i + 1][j - 1]);
                if (j < n - 1)
                    curr = min(curr, matrix[i + 1][j + 1]);

                matrix[i][j] += curr;
                // if (i == 0){
                //     ans = min(ans, matrix[i][j]);
                // }
            }
        }

        return *min_element(matrix[0].begin() , matrix[0].end());
    }
};