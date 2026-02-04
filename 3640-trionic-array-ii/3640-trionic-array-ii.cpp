class Solution {
    int n;
    typedef long long ll;
    vector<vector<ll>> dp;

private:
    long long solve(int idx , int tp , vector<int>& nums){
        if (idx == n){
            if (tp == 3) return 0;
            else return LLONG_MIN/2;
        }
        if (dp[idx][tp] != -1) return dp[idx][tp];

        ll take = LLONG_MIN/2;
        ll ntake = LLONG_MIN/2;

        if (tp == 0){
            ntake = solve(idx+1 , tp , nums);
        }
        if (tp == 3){
            take = nums[idx];
        }
        
        
        if (idx+1 < n){
            if (tp == 0  && nums[idx+1] > nums[idx]){
                take = max(take ,nums[idx] + solve(idx+1 , 1 , nums));
            }
            else if (tp == 1){
                if (nums[idx+1] > nums[idx]){
                    take = max(take ,nums[idx] + solve(idx+1 , 1 , nums));
                }
                else if (nums[idx+1] < nums[idx]){
                    take = max(take ,nums[idx] + solve(idx+1 , 2 , nums));
                }
            }
            else if (tp == 2){
                if (nums[idx+1] < nums[idx]){
                    take = max(take ,nums[idx] + solve(idx+1 , 2 , nums));
                }
                else if (nums[idx+1] > nums[idx]){
                    take = max(take ,nums[idx] + solve(idx+1 , 3 , nums));
                }
            }
            else if (tp == 3){
                if (nums[idx+1] > nums[idx]){
                    take = max(take ,nums[idx] + solve(idx+1 , 3 , nums));
                }
            }
        }
        return dp[idx][tp] = max(take , ntake);
    }
public:
    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        dp.assign(n+1 , vector<ll>(4 , -1));
        return solve(0,0,nums);
    }
};