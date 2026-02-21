class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans = 0;
        int n = nums.size();
        int m = pattern.size();

        for (int i = 0; i <= n - m - 1; i++) {
            int temp = 0;

            for (int j = 0; j < m; j++) {
                if (pattern[j] == 1 && nums[i + j + 1] > nums[i + j])
                    temp += 1;
                else if (pattern[j] == 0 && nums[i + j + 1] == nums[i + j])
                    temp += 1;
                else if (pattern[j] == -1 && nums[i + j + 1] < nums[i + j])
                    temp += 1;
                else
                    break;
            }

            if (temp == m)
                ans += 1;
        }

        return ans;
    }
};