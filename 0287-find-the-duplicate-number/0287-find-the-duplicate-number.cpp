class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sl = nums[0];
        int fst = nums[0];
        
        do{
            sl = nums[sl];
            fst = nums[nums[fst]];
        }while(sl != fst);

        fst = nums[0];
        while (fst != sl){
            sl = nums[sl];
            fst = nums[fst];
        }
        return sl;
    }
};