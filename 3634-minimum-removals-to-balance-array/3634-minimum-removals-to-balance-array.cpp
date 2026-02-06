class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int maxLen = 0;
        
        for (int j = 0; j < n; j++) {
            while ((long long)nums[j] > (long long)nums[i] * k) {
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        
        return n - maxLen;
    }
};

// class Solution {
// public:
//     int minRemoval(vector<int>& nums, int k) {
//         sort(nums.begin() , nums.end());
//         int n = nums.size();
//         if (n == 1) return 0;

//         int ans = 0;
//         int i =0 , j = n-1;
//         while (i <= j){
//             if (nums[j] <= k*nums[i]){
//                 ans = n-j+i-1;
//                 break;
//             }else if (nums[j-1] <= k*nums[i]){
//                 ans = n-(j-1)+i-1;
//                 break;
//             }
//             else if (nums[j] <= k*nums[i+1]){
//                 ans = n-j+i;
//                 break;
//             }
//             i += 1;
//             j -= 1;
//         }
//         return ans;
//     }
// };