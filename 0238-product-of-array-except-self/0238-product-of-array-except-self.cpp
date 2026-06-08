class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        int forward = 1 , backward = 1;
        vector<int> f(n) , b(n);
        for(int i=0;i<n;i++){
            forward *= nums[i];
            backward *= nums[n-1-i];
            f[i] = forward;
            b[n-1-i] = backward;
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if (i == 0) ans[i] = b[i+1];
            else if (i == n-1) ans[i] = f[i-1];
            else ans[i] = f[i-1]*b[i+1];
        }

        return ans;
    }
};