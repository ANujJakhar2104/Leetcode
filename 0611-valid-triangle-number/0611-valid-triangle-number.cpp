class Solution {
public:
    int bs(int st,int ed , vector<int>& nums , int sum){
        int ans = -1;
        while (st <= ed){
            int mid = st + (ed-st)/2;

            if (sum > nums[mid]){
                ans = mid;
                st = mid+1;
            }
            else{
                ed = mid-1;
            }
        }
        return ans;
    }

    int triangleNumber(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int count = 0;
        int n = nums.size();
        for(int i =0 ; i<n-2 ; i++){
            int sum = nums[i];
            for(int j = i+1 ; j < n-1 ; j++){
                sum += nums[j];
                int last = bs(j+1 , n-1 , nums , sum);
                if (last != -1){
                    count += (last - j);
                }
                sum-=nums[j];
            }
        }
        return count;
    }
};