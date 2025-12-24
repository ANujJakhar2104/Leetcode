class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long ans = LLONG_MAX;
        int n = s.length();
        vector<long long> temp(26,0);
        long long total = 0;
        for(int i=0;i<n;i++){
            temp[s[i]-'a'] += cost[i];
            total += cost[i];
        }

        for(int i=0;i<26;i++){
            if (temp[i] == 0) continue;

            ans = min(ans , total-temp[i]);
        }
        return ans;
    }
};