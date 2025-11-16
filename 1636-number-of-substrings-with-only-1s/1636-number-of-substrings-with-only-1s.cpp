class Solution {
public:
    const int MOD = 1e9 + 7;

    int numSub(string s) {
        long long x = 0;
        long long ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (x != 0) {
                    ans = (ans + (x * (x + 1) / 2) % MOD) % MOD;
                }
                x = 0;
            } else {
                x++;
            }
        }

        if (x != 0) {
            ans = (ans + (x * (x + 1) / 2) % MOD) % MOD;
        }

        return ans % MOD;
    }
};
