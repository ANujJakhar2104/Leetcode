class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> ans(m , -1);
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n ; i++){
            mp[nums[i]].push_back(i);
        }

        for(int i=0;i<m;i++){
            int a = queries[i];
            int curr = nums[a];
            auto &v = mp[curr];

            if (v.size() < 2) {
                ans[i] = -1;
                continue;
            }

            auto it = lower_bound(v.begin(), v.end(), a);
            int pos = it - v.begin();

            int mini = INT_MAX;

            if (pos > 0) {
                int d = abs(a - v[pos - 1]);
                mini = min(mini, min(d, n - d));
            } else {
                int d = abs(a - v.back());
                mini = min(mini, min(d, n - d));
            }

            if (pos < v.size() - 1) {
                int d = abs(a - v[pos + 1]);
                mini = min(mini, min(d, n - d));
            } else {
                int d = abs(a - v[0]);
                mini = min(mini, min(d, n - d));
            }

            ans[i] = mini;
        }
        return ans;

    }
};