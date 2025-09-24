class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        if (numerator == 0) return to_string(0);
        if ((numerator <0) ^ (denominator < 0) ) ans += '-';
        long long denominator_1 = llabs((long long) denominator);
        long long numerator_1 = llabs((long long)numerator);
        
        long long integer = numerator_1/denominator_1;
        long long rem = numerator_1%denominator_1;
        ans += to_string(integer);
        if (rem == 0) return ans;
        ans += '.';

        unordered_map<long long , int> mp;
        while (rem != 0){
            if (mp[rem]) {
                int index = mp[rem];
                ans.insert(index, "(");
                ans.push_back(')');
                break;
            }
            mp[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / denominator_1);
            rem %= denominator_1;
        }

        return ans ;
    }
};