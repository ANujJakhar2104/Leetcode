class Solution {
private:
    bool solve(int day, int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));

        for (int i = 0; i < day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<int>> vis(row, vector<int>(col, -1));

        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == row - 1) return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= row || nc < 0 || nc >= col ||
                    vis[nr][nc] != -1 || grid[nr][nc] == 1)
                    continue;

                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 1, high = cells.size();
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (solve(mid, row, col, cells)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
