class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i =0 , j=0;

        while (i < nums1.size() && j < nums2.size()){
            int curr1 = nums1[i][0] , val1 = nums1[i][1];
            int curr2 = nums2[j][0] , val2 = nums2[j][1];

            if (curr1 < curr2){
                ans.push_back({curr1 , val1});
                i++;
            }
            else if (curr2 < curr1){
                ans.push_back({curr2 , val2});
                j++;
            }
            else {
                ans.push_back({curr1 , val1+val2});
                i++;
                j++;
            }
        }
        while (i < nums1.size()){
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }
};