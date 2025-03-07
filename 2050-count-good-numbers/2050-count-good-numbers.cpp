class Solution {
public:
    const int MOD = 1000000007;

private:
    long long ans(long long n ,long long k) {
        long long result = 1;
        n %= MOD;

        while(k>0){
            if (k%2==1){
                result = (result * n)%MOD;
            }
            n = (n*n)%MOD;
            k /= 2;
        }
        return result%MOD;
    }

public:
    int countGoodNumbers(long long n) {
        if (n % 2 == 1) {
            return (5 * ans(20,n/2)) % MOD;
        } else {
            return ans(20 ,n/2) % MOD;
        }
    }
};
