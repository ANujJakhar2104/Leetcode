class Solution {
private:
    void found(int r, int c, vector<vector<int>>& vis, int row[], int col[], vector<vector<char>>& board) {
        vis[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + row[i];
            int nc = c + col[i];

            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() &&
                !vis[nr][nc] && board[nr][nc] == 'O') {
                found(nr, nc, vis, row, col, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                found(i, 0, vis, row, col, board);
            }
            if (!vis[i][n - 1] && board[i][n - 1] == 'O') {
                found(i, n - 1, vis, row, col, board);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[0][i] && board[0][i] == 'O') {
                found(0, i, vis, row, col, board);
            }
            if (!vis[m - 1][i] && board[m - 1][i] == 'O') {
                found(m - 1, i, vis, row, col, board);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
