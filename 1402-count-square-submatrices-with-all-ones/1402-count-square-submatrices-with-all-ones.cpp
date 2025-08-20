// class Solution {
// public:
//     int countSquares(vector<vector<int>>& matrix) {
//        int sum = 0;
//        int row = matrix.size();
//         int col = matrix[0].size();
//        for(int i = 0; i < row ; i++){
//         for(int j =0 ;j < col ; j++){
//             sum += matrix[i][j];
//             matrix[i][j] = sum;
//             if (j == col-1) sum = 0;
//         }
//        }
//        int ans = 0;
//        for(int i =0 ; i< row ;i++){
//             for(int j = 0; j < col ; j++){
//                 if (matrix[i][j] >= 1) ans++;
//                 if ()
//             }
//        }
//     }
// };

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] = 1 + min({matrix[i - 1][j], matrix[i][j - 1],
                                            matrix[i - 1][j - 1]});
                }
                ans += matrix[i][j];
            }
        }

        return ans;
    }
};
