class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int i = 0, j = 0;
        int zr = 0;

        while (j < nums.size()) {
            if (nums[j] == 0) {
                if (zr == 0) {
                    zr = 1;
                } else {
                    ans = max(ans, j - i - 1);
                    while (zr != 0) {
                        if (nums[i] == 0) zr--;
                        i++;
                    }
                    zr = 1;
                }
            }
            j++;
        }

        ans = max(ans, j - i - 1);

        return ans;
    }
};
