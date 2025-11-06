class Solution {
public:
     map<int,set<int>>mp;
     map<int,int>grid;

     void dfs(vector<vector<int>>&adj,int u,vector<bool>&visited,int component){
         visited[u] = true;
         mp[component].insert(u);
         grid[u] = component;

         for(auto& v:adj[u]){
            if(!visited[v]) dfs(adj,v,visited,component);
         }

         return;
     }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        set<int>st;
        vector<vector<int>>adj(c+1);

        for(auto &it:connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(c+1,false);

        int component = 0;

        for(int i=1;i<=c;i++){
            if(!visited[i]){
                dfs(adj,i,visited,component);
                component++;
            }
        }

        vector<int>ans;

        for(auto &q : queries){
            int node = q[1];
            int type = q[0];
            int comp = grid[node];
            if(type==2){
                mp[comp].erase(node);
                st.insert(node);
            }
            else{
               if(!st.count(node)) ans.push_back(node);
               else{
                   if(!mp[comp].empty()) ans.push_back(*mp[comp].begin());
                   else ans.push_back(-1);
               }
            }
        }

        return ans;

    }
};
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     vector<int> processQueries(int c,
//                                vector<vector<int>>& connections,
//                                vector<vector<int>>& queries) {
//         vector<vector<int>> g(c + 1);
//         for (auto &e : connections) {
//             int u = e[0], v = e[1];
//             g[u].push_back(v);
//             g[v].push_back(u);
//         }

//         vector<int> comp_id(c + 1, -1);
//         int comp_cnt = 0;
//         for (int i = 1; i <= c; ++i) {
//             if (comp_id[i] != -1) continue;
//             queue<int> q;
//             q.push(i);
//             comp_id[i] = comp_cnt;
//             while (!q.empty()) {
//                 int u = q.front(); q.pop();
//                 for (int v : g[u]) {
//                     if (comp_id[v] == -1) {
//                         comp_id[v] = comp_cnt;
//                         q.push(v);
//                     }
//                 }
//             }
//             ++comp_cnt;
//         }

//         vector< set<int> > comp_offline(comp_cnt);
//         vector<int> online(c + 1, 0);
//         for (int node = 1; node <= c; ++node) {
//             comp_offline[comp_id[node]].insert(node);
//         }

//         vector<int> ans;
//         for (auto &qv : queries) {
//             int type = qv[0], x = qv[1];
//             int cid = comp_id[x];

//             if (type == 1) {
//                 if (online[x] == 0) {
//                     ans.push_back(x);
//                 } else {
//                     if (!comp_offline[cid].empty()) {
//                         ans.push_back(*comp_offline[cid].begin());
//                     } else {
//                         ans.push_back(-1);
//                     }
//                 }
//             } else {
//                 if (online[x] == 0) {
//                     online[x] = 1;
//                     comp_offline[cid].erase(x);
//                 }
//             }
//         }

//         return ans;
//     }
// };
