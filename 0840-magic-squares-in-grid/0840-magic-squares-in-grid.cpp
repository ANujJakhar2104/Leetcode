class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int answer = 0;

        if (m < 3 || n < 3)
            return 0;

        for (int i = 0; i + 2 < m; i++) {
            for (int j = 0; j + 2 < n; j++) {

                if (grid[i + 1][j + 1] != 5)
                    continue;

                vector<int> used(10, 0);
                vector<int> row(3, 0), col(3, 0);

                int d1 = grid[i][j]+grid[i + 1][j + 1] + grid[i + 2][j + 2];
                int d2 = grid[i][j + 2]+grid[i + 1][j + 1] + grid[i + 2][j];

                if (d1 != d2)
                    continue;

                bool ok = true;

                for (int r = i; r < i + 3; r++) {
                    for (int c = j; c < j + 3; c++) {
                        int val = grid[r][c];

                        if (val < 1 || val > 9 || used[val]) {
                            ok = false;
                            break;
                        }

                        used[val] = 1;
                        row[r - i] += val;
                        col[c - j] += val;
                    }
                    if (!ok)
                        break;
                }

                if (!ok)
                    continue;

                for (int x = 0; x < 3; x++) {
                    if (row[x] != d1 || col[x] != d1) {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                    answer++;
            }
        }

        return answer;
    }
};
