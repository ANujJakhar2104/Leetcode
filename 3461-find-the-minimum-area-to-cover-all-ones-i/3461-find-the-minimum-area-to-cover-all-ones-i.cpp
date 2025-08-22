class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int st_row = -1, ed_row = -1;
        int st_col = -1, ed_col = -1;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    if (st_row == -1) st_row = i;
                    ed_row = i;

                    if (st_col == -1 || j < st_col) st_col = j;
                    if (ed_col == -1 || j > ed_col) ed_col = j;
                }
            }
        }

        if (st_row == -1) return 0;

        return (ed_row - st_row + 1) * (ed_col - st_col + 1);
    }
};
