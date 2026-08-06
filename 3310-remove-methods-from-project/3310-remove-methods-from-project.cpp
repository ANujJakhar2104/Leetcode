class Solution {
public:
    bool found = false;
    void solve(int color ,int idx ,vector<int>& vis ,vector<vector<int>>& adj){
        queue<int> q;
        q.push(idx);
        vis[idx] = color;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int next : adj[node]){
                if (vis[next] == 1 && color == 2){
                    found = true;
                    return;
                }

                if (vis[next] != color){
                    vis[next] = color;
                    q.push(next);
                }
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invo) {
        vector<vector<int>> adj(n);

        for(auto it : invo){
            int a = it[0] , b = it[1];
            adj[a].push_back(b);
        }

        vector<int> vis(n , -1);
        solve(1 , k , vis , adj);
        
        for(int i =0; i<n;i++){
            if (vis[i] != -1) continue;
            solve(2 ,i, vis , adj);
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if (vis[i] == 1 && !found) continue;
            ans.push_back(i);
        }

        return ans;
    }
};