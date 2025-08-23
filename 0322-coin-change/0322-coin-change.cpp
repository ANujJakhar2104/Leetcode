class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount +1 , 0);
        for(int i =0 ;i <= amount ; i++){
            if (i % coins[0] ==0 ){
                prev[i] = i/coins[0];
            }
            else{
                prev[i] = 1e9;
            }
        }

        for(int i = 1 ; i < coins.size() ; i++){
            vector<int> curr(amount+1 , 0);
            for(int sum = 0 ; sum <= amount ; sum++){
                int ntake = prev[sum];
                int take = INT_MAX;
                if (coins[i] <= sum) take = 1 + curr[sum - coins[i]];

                curr[sum] = min(take , ntake);
            }
            prev = curr;
        }
        return prev[amount] >= 1e9 ? -1 : prev[amount];
    }

};