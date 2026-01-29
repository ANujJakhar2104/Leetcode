class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        vector<vector<pair<int,int>>> mp(26);
        vector<vector<int>> dp(26, vector<int>(26, INT_MAX));
        int n = original.size();

        for (int i = 0; i < n; i++) {
            mp[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }

        long long ans = 0;

        for (int i = 0; i < source.size(); i++) {
            int sr = source[i] - 'a';
            int tar = target[i] - 'a';

            if (sr == tar) continue;

            if (dp[sr][tar] != INT_MAX) {
                ans += dp[sr][tar];
                continue;
            }

            vector<int> dist(26, INT_MAX);
            queue<pair<int,int>> q;

            dist[sr] = 0;
            q.push({0, sr});

            int temp = INT_MAX;

            while (!q.empty()) {
                int ct = q.front().first;
                int curr = q.front().second;
                q.pop();

                if (ct > dist[curr]) continue;

                if (curr == tar) {
                    temp = min(temp, ct);
                    continue;
                }

                for (auto &it : mp[curr]) {
                    int nxt = it.first;
                    int w = it.second;

                    if (dist[nxt] > ct + w) {
                        dist[nxt] = ct + w;
                        q.push({dist[nxt], nxt});
                    }
                }
            }

            if (temp == INT_MAX) return -1;

            dp[sr][tar] = temp;
            ans += temp;
        }

        return ans;
    }
};
