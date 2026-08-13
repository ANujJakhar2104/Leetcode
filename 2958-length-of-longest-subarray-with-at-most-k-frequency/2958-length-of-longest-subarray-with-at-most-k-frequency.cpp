class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i =0 ,j=0;

        unordered_map<int,int> mp;
        int ans = 0;

        while (j < n){
            mp[nums[j]] +=1;
            if (mp[nums[j]] <= k){
                ans = max(ans , j-i+1);
            }else {
                while (mp[nums[j]] > k){
                    mp[nums[i]] -= 1;
                    if (mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
            }
            j++;
        }

        return ans;
    }
};