class Solution {
public:
    bool istarget(int n , int target , vector<int>& nums){
        vector<bool> prev(target+1 , false) , curr(target+1 , false);
        prev[0] = curr[0] = true;
        if (nums[0] <= target) prev[nums[0]] = true;

        for( int i = 1 ; i< n ; i++){
            for(int j = 1 ; j <= target ; j++){
                bool ntake = prev[j];
                bool take = false;
                if (nums[i] <= j) take = prev[j - nums[i]];

                curr[j] = take | ntake;
            }
            prev = curr;
        }
        return prev[target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums )sum += it;
        if (sum&1) return false;
        int target = sum/2;
        int n = nums.size();

        return istarget(n , target , nums);
    }
};