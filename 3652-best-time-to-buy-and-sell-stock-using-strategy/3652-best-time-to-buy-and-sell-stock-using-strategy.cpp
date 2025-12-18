class Solution {
public:
    using ll = long long;

    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<ll> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + 1LL * strategy[i] * prices[i];
        }

        ll ans = prefix[n];
        ll temp = 0;
        
        for (int i = k/2; i < k; i++) {
            temp += prices[i];
        }

        ans = max(ans, temp + prefix[n] - prefix[k]);

        for (int i = 1; i + k <= n; i++) {
            temp += prices[i + k - 1];
            temp -= prices[i + (k/2) - 1];

            ll curr = temp + prefix[n] - prefix[i + k] + prefix[i];
            ans = max(ans, curr);
        }

        return ans;
    }
};
