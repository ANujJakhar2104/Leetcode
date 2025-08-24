class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1

        for coin in coins:
            new_dp = [0] * (amount + 1)
            for j in range(amount + 1):
                ntake = dp[j]
                take = 0
                if coin <= j:
                    take = new_dp[j - coin]
                new_dp[j] = take + ntake
            dp = new_dp

        return dp[amount]
