class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n);
        vector<int> mini(n);

        mini[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            mini[i] = min(nums[i], mini[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            prefix[i] = nums[i];
            if (i > 0) prefix[i] += prefix[i - 1];
        }

        long long ans = LLONG_MIN;
        for (int i = 0; i < n-1; i++) {
            ans = max(ans, prefix[i] - mini[i + 1]);
        }

        return ans;
    }
};
