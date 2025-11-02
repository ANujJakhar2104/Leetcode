#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto &w : walls)
            grid[w[0]][w[1]] = 1;

        for (auto &g : guards)
            grid[g[0]][g[1]] = 2;

        for (auto &g : guards) {
            int i = g[0], j = g[1];
            int a, b;

            // up
            a = i - 1, b = j;
            while (a >= 0 && grid[a][b] != 1 && grid[a][b] != 2) {
                if (grid[a][b] == -1) { a--; continue; } // already marked, skip fast
                grid[a][b] = -1;
                a--;
            }

            // down
            a = i + 1, b = j;
            while (a < m && grid[a][b] != 1 && grid[a][b] != 2) {
                if (grid[a][b] == -1) { a++; continue; }
                grid[a][b] = -1;
                a++;
            }

            // left
            a = i, b = j - 1;
            while (b >= 0 && grid[a][b] != 1 && grid[a][b] != 2) {
                if (grid[a][b] == -1) { b--; continue; }
                grid[a][b] = -1;
                b--;
            }

            // right
            a = i, b = j + 1;
            while (b < n && grid[a][b] != 1 && grid[a][b] != 2) {
                if (grid[a][b] == -1) { b++; continue; }
                grid[a][b] = -1;
                b++;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                    ans++;

        return ans;
    }
};
