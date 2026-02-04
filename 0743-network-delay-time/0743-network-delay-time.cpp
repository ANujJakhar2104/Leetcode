class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            int sr = it[0], tr = it[1], tm = it[2];
            adj[sr].push_back({tr, tm});
        }

        vector<int> vis(n+1, INT_MAX);
        queue<int> q;
        
        q.push(k);
        vis[k] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                int nxt = it.first;
                int weight = it.second;

                if (vis[node] + weight < vis[nxt]) {
                    vis[nxt] = vis[node] + weight;
                    q.push(nxt);
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if (vis[i] == INT_MAX) return -1;
            ans = max(ans, vis[i]);
        }
        return ans;
    }
};