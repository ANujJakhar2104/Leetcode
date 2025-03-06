class Solution {
// private:
// double power(double x , int n){
//     if (n==1) return x;
//     return power(x,n-1) * x;
// }
public:
    double myPow(double x, long n) {
        if (n==0) return 1;
        if (x==1) return 1;
        
        if (n<0) {
            return 1.0 / myPow(x , -n);
        }

        if (n%2 == 1) return x * myPow(x*x , (n-1)/2);
        else return myPow(x*x , n/2);
    }
};