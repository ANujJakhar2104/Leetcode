class Solution {
    int n;

private:
    bool check(long long mid, int k, vector<long long>& diff, int r) {
        vector<long long> diff2 = diff;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff2[i];
            if (sum < mid) {
                long long need = mid - sum;
                if (need > k) {
                    return false;
                }
                sum += need;
                k -= need;

                if (i + 2 * r + 1 < n)
                    diff2[i + 2 * r + 1] -= need;
            }
        }

        return true;
    }

public:
    long long maxPower(vector<int>& stations, int r, int k) {
        n = stations.size();
        vector<long long> diff(n, 0);
        for (int i = 0; i < n; i++) {
            diff[max(0, i - r)] += stations[i];

            if (i + r + 1 < n) {
                diff[i + r + 1] -= stations[i];
            }
        }

        // for (int i = 1; i < n; i++)
        //     diff[i] += diff[i - 1];
        
        long long st = *min_element(diff.begin(), diff.end());
        long long ed = accumulate(diff.begin(), diff.end(), 0ll) + k;

        long long result = 0;
        while (st <= ed) {
            long long mid = st + (ed - st) / 2;

            if (check(mid, k, diff, r)) {
                result = mid;
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        return result;
    }
};

// there is use of dat or diffrence array technique
