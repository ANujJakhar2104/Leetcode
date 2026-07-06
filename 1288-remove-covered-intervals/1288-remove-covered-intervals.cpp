class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        sort(nums.begin() , nums.end() ,  [](vector<int>&a, vector<int>&b){
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        int cnt = 0;
        int maxi = 0;
        for(int i=0;i<nums.size()-1;i++){
            if ((nums[i][1] >= nums[i+1][1]) || (maxi >= nums[i+1][1])){
                cnt += 1;
                maxi = max(maxi , nums[i][1]);
            }
        }

        return nums.size() - cnt;
    }
};