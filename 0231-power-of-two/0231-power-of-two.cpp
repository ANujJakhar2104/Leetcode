class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n % 2 == 1) return n == 1;
        
        while (n > 1) {
            n = n >> 1;
            if (n % 2 == 1 && n!=1) return false;
        }
        return true;
    }
};
