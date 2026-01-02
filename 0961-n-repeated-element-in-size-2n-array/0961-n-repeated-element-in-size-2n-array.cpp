class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n =nums.size();
        for(int i=0;i<n;i++){
            if (i < n-1 && nums[i]==nums[i+1]){
                return nums[i];
            }
            else if (i < n-2 && nums[i] == nums[i+2]){
                return nums[i];
            }
        }
        return nums[0]==nums[n-1] ? nums[0] : -1;
    }
};