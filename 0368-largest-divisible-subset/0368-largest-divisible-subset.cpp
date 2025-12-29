class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<int> mp(n);
        vector<int> dp(n,1);

        int maxi = 1;
        int lastindex = 0;
        for(int i=1;i<n;i++){
            mp[i] = i;
            for(int j=0;j<i;j++){
                if (nums[i]%nums[j]==0 && 1+dp[j] > dp[i]){
                    dp[i] = 1+dp[j];
                    mp[i] = j;
                }
            }
            if (dp[i] > maxi){
                maxi = dp[i];
                lastindex = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastindex]);

        while (mp[lastindex] != lastindex){
            lastindex = mp[lastindex];
            ans.push_back(nums[lastindex]);
        }
        reverse(ans.begin() , ans.end());
        return  ans;
    }
};