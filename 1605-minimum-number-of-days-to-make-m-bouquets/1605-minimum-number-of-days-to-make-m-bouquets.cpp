class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (1LL * m * k > n) return -1;
        
        int st = 1;
        int ed = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (st <= ed) {
            int mid = st + (ed - st) / 2;
            int cons = 0;
            int sz = m;

            for (auto it : bloomDay) {
                if (it <= mid) cons++;
                else cons = 0;

                if (cons == k) {
                    sz--;
                    cons = 0;
                }
            }

            if (sz > 0) {
                st = mid + 1;
            } else {
                ans = mid;
                ed = mid - 1;
            }
        }
        return ans;
    }
};
