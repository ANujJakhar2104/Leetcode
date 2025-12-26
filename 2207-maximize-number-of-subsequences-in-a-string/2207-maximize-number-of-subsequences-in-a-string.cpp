class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long count_fst = 0;
        long long count_snd = 0;
        char first = pattern[0], second = pattern[1];

        long long ans = 0;
        int n = text.size();

        for (int i = 0; i < n; i++) {
            if (text[i] == first) {
                count_fst++;
            } else if (text[i] == second) {
                count_snd++;
                ans += count_fst;
            }
        }

        if (first == second) {
            return 1LL * (count_fst + 1) * count_fst / 2;
        }

        return ans + max(count_snd, count_fst);
    }
};
