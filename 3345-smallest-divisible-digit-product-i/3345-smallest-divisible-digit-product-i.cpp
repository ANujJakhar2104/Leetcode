class Solution {
public:
    int smallestNumber(int n, int t) {
        int temp = n;
        int ans = 1;
        while(temp > 0){
            ans *= temp%10;
            temp /= 10;
        }

        if (ans == 0 || ans%t == 0) return n;
        int x = n % 10;
        ans /= x;
        for (int i = 1; i <= 9 - x; i++) {
            if ((ans * (x + i)) % t == 0) return n + i;
        }
        return n + (10 - x);
    }
};