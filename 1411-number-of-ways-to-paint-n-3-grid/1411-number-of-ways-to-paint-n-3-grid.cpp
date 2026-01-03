class Solution {
public:
    static const int mod = 1e9 + 7;

    int numOfWays(int n) {
        if (n == 1) return 12;
        long long two = 6, three = 6;
        for (int i = 2; i <= n; i++) {
            long long two_same = (2 * three + 3 * two) % mod;
            long long three_diff = (2 * three + 2 * two) % mod;
            two = two_same;
            three = three_diff;
        }
        return (two + three) % mod;
    }
};
