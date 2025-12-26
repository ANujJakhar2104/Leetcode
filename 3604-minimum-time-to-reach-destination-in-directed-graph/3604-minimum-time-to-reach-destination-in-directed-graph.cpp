class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, pair<int, int>>>> adj(n);

        for (auto& it : edges) {
            int a = it[0], b = it[1], st = it[2], ed = it[3];
            adj[a].push_back({b, {st, ed}});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;

        vector<int> dist(n, INT_MAX);

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            int curr_st = pq.top().first;
            int curr_node = pq.top().second;
            pq.pop();

            if (curr_node == n - 1)
                return curr_st;

            if (curr_st > dist[curr_node])
                continue;

            for (auto& it : adj[curr_node]) {
                int next_node = it.first;
                int next_st = it.second.first;
                int next_ed = it.second.second;

                int arrive;

                if (curr_st >= next_st && curr_st <= next_ed)
                    arrive = curr_st + 1;
                else if (curr_st < next_st)
                    arrive = next_st + 1;
                else
                    continue;

                if (arrive < dist[next_node]) {
                    dist[next_node] = arrive;
                    pq.push({arrive, next_node});
                }
            }
        }

        return -1;
    }
};
