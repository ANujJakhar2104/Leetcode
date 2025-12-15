class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n , 0);
        long long sum = 0;
        if (n == 1) return 1;

        for(int i = 0;i < n-1;i++){
            if (prices[i]-prices[i+1] == 1){
                if (i>0) ans[i] = 1 + ans[i-1];
                if (i == 0) ans[i] = 1;
            }
            sum += ans[i];
        }
        return sum + n;
    }
};