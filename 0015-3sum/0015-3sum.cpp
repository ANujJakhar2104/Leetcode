class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin() , nums.end());
        int n = nums.size();

        for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1;j<n-1;j++){
                int sum = nums[i] + nums[j];
                int st = j+1 , ed = n-1;

                while (st <= ed){
                    int mid = st + (ed-st)/2;
                    if (nums[mid] == -sum){
                        ans.insert({nums[i], nums[j], nums[mid]});
                        break;
                    }else if (nums[mid] > -sum){
                        ed = mid-1;
                    }else st = mid+1;
                }
            }
        }

        return vector<vector<int>>(ans.begin() , ans.end());
    }
};