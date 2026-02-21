class Solution {
public:
    int bit(int n){
        int cnt = 0;
        while (n > 0){
            if (n&1) cnt += 1;
            n >>=1;
        }
        return cnt;
    }
    bool isprime(int n){
        if (n == 1) return false;
        bool res = true;
        for(int i=2;i*i<=n;i++){
            if (n%i == 0) {
                res = false;
                break;
            }
        }
        return res;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i=left ; i<=right ;i++){
            if (isprime(bit(i))){
                ans += 1;
            }
        }
        return ans;
    }
};