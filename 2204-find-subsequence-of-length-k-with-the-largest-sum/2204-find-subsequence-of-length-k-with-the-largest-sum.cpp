class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> copy;
        
        for (int i = 0; i < n; i++) {
            copy.push_back({nums[i], i});
        }

        sort(copy.begin(), copy.end());

        vector<int> index;
        for (int i = n - k; i < n; i++) {
            index.push_back(copy[i].second);
        }

        sort(index.begin(), index.end());

        vector<int> ans;
        for (int a : index) {
            ans.push_back(nums[a]);
        }

        return ans;
    }
};
