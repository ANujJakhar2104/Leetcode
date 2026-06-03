class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n-1;j++){
                int lo = j + 1, hi = n - 1;
                while (lo <= hi) {
                    int mid = lo + (hi-lo)/2;
                    int sum = nums[i] + nums[j] + nums[mid];
                    if (sum == 0) {
                        ans.insert({nums[i], nums[j], nums[mid]});
                        break;
                    }
                    else if (sum < 0) lo = mid+1;
                    else hi = mid-1;
                }
            }
        }
        return vector<vector<int>>(ans.begin() , ans.end());
    }
};