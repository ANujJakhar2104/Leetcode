class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(int num : nums){
            long long temp =0;
            int cnt = 0;
            for(int i=1;i*i<=num;i++){
                if (num%i==0){
                    cnt++;
                    temp += i;
                    if (i != num/i){
                        cnt++;
                        temp += num/i;
                    }
                }
            }
            if (cnt == 4){
                ans += temp;
            }
        }

        return int(ans);
    }
};