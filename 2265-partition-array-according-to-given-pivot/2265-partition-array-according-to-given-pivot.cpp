class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ls, eq, gt;
        
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                ls.push_back(nums[i]);
            }
            else if (nums[i] > pivot) {
                gt.push_back(nums[i]);
            }
            else {
                eq.push_back(nums[i]);
            }
        }

        ls.insert(ls.end(), eq.begin(), eq.end());
        ls.insert(ls.end(), gt.begin(), gt.end());

        return ls;

        // int i=0 , j= nums.size()-1;
        // while (i <= j) {
        //     while (i < nums.size() && nums[i] < pivot) i++;
        //     while (j >= 0 && nums[j] > pivot) j--;
            
        //     if (i <= j) {
        //         swap(nums[i], nums[j]);
        //         i++;
        //         j--;
        //     }
        // }
        
        // return nums;
    }
};
