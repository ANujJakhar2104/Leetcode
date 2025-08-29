class Solution {
public:
    long long flowerGame(int n, int m) {
        int ev = m/2;
        int od = m - ev;
        long long ans = 0;
        if (n == 1 && m == 1) return 0;
        
        for(int i = 1; i <= n ;i++){
            if (i&1){
                ans += ev;
            }
            else {
                ans += od;
            }
        }

        return ans;
    }
};