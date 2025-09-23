class Solution {
public:
    int compareVersion(string s, string t) {
        int sz1 = s.size(), sz2 = t.size();
        int i = 0, j = 0;
        while (i < sz1 || j < sz2) {
            int first = 0;
            while (i < sz1 && s[i] != '.') {
                first = first * 10 + (s[i] - '0');
                i++;
            }
            i++;

            int second = 0;
            while (j < sz2 && t[j] != '.') {
                second = second * 10 + (t[j] - '0');
                j++;
            }
            j++;

            if (first > second) return 1;
            else if (first < second) return -1;
        }
        return 0;
    }
};