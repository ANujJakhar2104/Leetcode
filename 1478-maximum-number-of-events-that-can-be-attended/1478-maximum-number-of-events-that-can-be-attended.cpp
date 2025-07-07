#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int parent[100005];

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int lastDay = 0;
        for (auto& e : events)
            lastDay = max(lastDay, e[1]);

        for (int i = 0; i <= lastDay + 1; i++)
            parent[i] = i;

        int ans = 0;
        for (auto& e : events) {
            int day = find(e[0]);
            if (day <= e[1]) {
                ans++;
                parent[day] = find(day + 1);
            }
        }
        return ans;
    }
};
