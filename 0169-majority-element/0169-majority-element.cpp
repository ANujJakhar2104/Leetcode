class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int freq = 1;

        for(int i=1;i<nums.size();i++){
            if(nums[i] == num) freq += 1;
            else{
                if (freq == 1) num = nums[i];
                else freq -= 1;
            }
        }

        return num;
    }
};