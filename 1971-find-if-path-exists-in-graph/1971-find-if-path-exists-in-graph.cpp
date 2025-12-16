class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;

        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);

        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<int> q;
        q.push(source);
        vis[source] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int x : adj[curr]) {
                if (x == destination) return true;
                if (!vis[x]) {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        return false;
    }
};
