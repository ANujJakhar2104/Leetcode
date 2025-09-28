class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();

        for(int k = n-1; k >=2 ;k--){
            int sum = nums[k-1] + nums[k-2];
            if (sum > nums[k]){
                return sum + nums[k];
            }
        }
        return 0;
    }
};