class Solution {
public:
    int minimumK(vector<int>& nums) {
        long long  k = 0;
        long long  ans = LLONG_MAX;

        int i=1;
        int j= max(*max_element(nums.begin(), nums.end()), (int)nums.size());

        while (i<=j){
            k = i + (j-i)/2;
            long long  temp=0;
            for(int a : nums) {
                if (a%k) temp += 1;
                temp += a/k;
            }
            if (temp <= k*k){
                j = k-1;
                ans = min(ans , k);
            }else {
                i = k+1;
            }
        }

        return ans;
    }
};