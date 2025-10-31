class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n-2 , 0);
        vector<int> ans;
        for(int num : nums){
            arr[num]++;
            if(arr[num] == 2) ans.push_back(num);
        }

        return ans;
    }
};