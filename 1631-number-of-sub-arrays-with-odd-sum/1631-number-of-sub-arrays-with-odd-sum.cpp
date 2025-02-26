class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    int numOfSubarrays(vector<int>& arr) {
        long long count = 0;
        long long prefixSum = 0;
        long long oddCount = 0, evenCount = 1;

        for (int num : arr) {
            prefixSum += num;

            if (prefixSum % 2 == 1) {
                count = (count + evenCount) % MOD;
                oddCount++;
            } else {
                count = (count + oddCount) % MOD;
                evenCount++;
            }
        }

        return count;
    }
};
