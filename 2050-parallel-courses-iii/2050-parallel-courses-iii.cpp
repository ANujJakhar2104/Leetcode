class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> inorder(n+1, 0);
        vector<vector<int>> adj(n+1);

        for (auto it : relations) {
            int a = it[0], b = it[1];
            inorder[b] += 1;
            adj[a].push_back(b);
        }

        queue<int> q;
        vector<long long> dp(n+1 , 0);
        for (int i = 1; i <= n; i++) {
            if (inorder[i] == 0)
                q.push(i);
                dp[i] = time[i-1];
        }

        int ans = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int temp : adj[curr]) {
                dp[temp] = max(dp[temp],dp[curr]+time[temp-1]);
                inorder[temp] -= 1;
                if (inorder[temp] == 0) {
                    q.push(temp);
                }
            }
        }

        return *max_element(dp.begin() , dp.end());
    }
};