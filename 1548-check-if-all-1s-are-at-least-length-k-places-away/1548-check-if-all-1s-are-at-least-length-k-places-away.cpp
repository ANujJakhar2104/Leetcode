class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool found = false;
        int temp = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 1){
                if (found) {
                    if (temp < k) return false;
                }
                found = true;
                temp = 0;
            } 
            else {
                if (found) temp++;
            }
        }

        return true;
    }
};
