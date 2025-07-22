class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, sum = 0, maxi = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                sum -= nums[left];
                ++left;
            }
            seen.insert(nums[right]);
            sum += nums[right];
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};
