#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> processQueries(int c,
                               vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<vector<int>> g(c + 1);
        for (auto &e : connections) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> comp_id(c + 1, -1);
        int comp_cnt = 0;
        for (int i = 1; i <= c; ++i) {
            if (comp_id[i] != -1) continue;
            queue<int> q;
            q.push(i);
            comp_id[i] = comp_cnt;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : g[u]) {
                    if (comp_id[v] == -1) {
                        comp_id[v] = comp_cnt;
                        q.push(v);
                    }
                }
            }
            ++comp_cnt;
        }

        vector< set<int> > comp_offline(comp_cnt);
        vector<int> online(c + 1, 0);
        for (int node = 1; node <= c; ++node) {
            comp_offline[comp_id[node]].insert(node);
        }

        vector<int> ans;
        for (auto &qv : queries) {
            int type = qv[0], x = qv[1];
            int cid = comp_id[x];

            if (type == 1) {
                if (online[x] == 0) {
                    ans.push_back(x);
                } else {
                    if (!comp_offline[cid].empty()) {
                        ans.push_back(*comp_offline[cid].begin());
                    } else {
                        ans.push_back(-1);
                    }
                }
            } else {
                if (online[x] == 0) {
                    online[x] = 1;
                    comp_offline[cid].erase(x);
                }
            }
        }

        return ans;
    }
};
