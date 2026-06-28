class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin() , nums.end());
        int ans = 0;

        for(int num : mp){
            if (mp.find(num-1) == mp.end()){
                int k = 1;
                while (mp.find(num+k) != mp.end()){
                    k++;
                }
                ans = max(ans , k);
            }
        }
        return ans;
    }
};
