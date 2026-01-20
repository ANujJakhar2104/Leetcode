class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans (n, -1);

        for(int i=0;i<n;i++){
            int p = 0;
            while (p<32){
                int curr = nums[i] - (1<<p);
                if (curr < 0) break;
                if ((curr | curr+1) == nums[i]){
                    ans[i] = curr;
                }
                p++;
            }
        }
        return ans;
    }
};
