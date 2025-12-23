class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int best = 0;
        int answer = 0;

        for (auto& it : events) {
            int st = it[0], ed = it[1], value = it[2];

            while (!pq.empty() && pq.top().first < st) {
                best = max(best, pq.top().second);
                pq.pop();
            }

            answer = max(answer, best + value);
            pq.push({ed, value});
        }

        return answer;
    }
};
