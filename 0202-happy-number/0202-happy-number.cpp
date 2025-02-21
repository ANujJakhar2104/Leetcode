class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visit;

        while(n!=1 && visit.find(n) == visit.end()){
            visit.insert(n);
            int sum =0;
            while(n>0){
                int i = n%10;
                sum += i*i;
                n/=10;
            }
            n = sum;
        }
        return n==1;
    }
};