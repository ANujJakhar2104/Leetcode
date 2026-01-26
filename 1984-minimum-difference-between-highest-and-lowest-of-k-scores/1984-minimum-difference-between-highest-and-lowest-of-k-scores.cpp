class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin() , nums.end());
        int i=0,j=0;
        int ans = INT_MAX;
        while (j!=n){
            if (j-i+1 == k){
                ans = min(ans , nums[j]-nums[i]);
                i++;
            }
            j += 1;
        }
        return ans;
    }
};