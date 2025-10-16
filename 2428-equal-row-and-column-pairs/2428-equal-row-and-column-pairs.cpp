class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> mp;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            string s;
            for (int j = 0; j < n; j++) s += to_string(grid[i][j]) + ",";
            mp[s]++;
        }

        for (int j = 0; j < n; j++) {
            string s;
            for (int i = 0; i < n; i++) s += to_string(grid[i][j]) + ",";
            ans += mp[s];
        }

        return ans;
    }
};
