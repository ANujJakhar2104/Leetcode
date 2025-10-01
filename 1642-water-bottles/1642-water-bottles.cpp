class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange){
            ans += numBottles / numExchange;
            int remain = numBottles % numExchange;
            numBottles /= numExchange;
            numBottles += remain;
        }
        return ans;
    }
};