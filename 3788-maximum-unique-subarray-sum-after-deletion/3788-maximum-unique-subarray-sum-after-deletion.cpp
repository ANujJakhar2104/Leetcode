class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> unique(nums.begin(), nums.end());
        int sum = INT_MAX;
        int maxi = INT_MIN;
        for (int num : unique) {
            maxi = max(num , maxi);
            if (num >= 0){
                if (sum == INT_MAX) sum = 0;
                sum += num;
            }
        }
        if (sum == INT_MAX) return maxi;
        return sum;
    }
};
