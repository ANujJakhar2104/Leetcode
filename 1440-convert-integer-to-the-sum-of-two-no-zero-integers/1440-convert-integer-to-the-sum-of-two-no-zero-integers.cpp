class Solution {
public:
    bool check(int x){
        while (x > 0) {
            if (x % 10 == 0) return false;
            x /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            if (check(i) && check(n-i)){
                return {i , n-i};
            }
        }
        return {};
    }
};