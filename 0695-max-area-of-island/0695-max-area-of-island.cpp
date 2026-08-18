class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m , vector<int>(n , -1));

        queue<pair<int,int>> q;
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (grid[i][j] == 1 && vis[i][j] == -1){
                    int temp = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = 1;

                    while (!q.empty()){
                        auto [ii , jj] = q.front();
                        q.pop();
                        temp += 1;

                        int x[4] = {1,0,-1,0};
                        int y[4] = {0,1,0,-1};
                        
                        for(int k=0;k<4;k++){
                            int new_x = ii + x[k];
                            int new_y = jj + y[k];

                            if (new_x < 0 || new_x >=m || new_y <0 || new_y >= n) continue;
                            
                            if (grid[new_x][new_y] == 1 && vis[new_x][new_y] == -1) {
                                vis[new_x][new_y] = 1;
                                q.push({new_x , new_y});
                            }
                        }

                    }

                    ans = max(ans , temp);
                }
            }
        }
        return ans;

    }
};