class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        if (digits[n-1] == 9){
            digits[n-1] = 0;
            carry = 1;
        }
        else {
            digits[n-1] += 1;
            return digits;
        }
        
        for(int i=n-2;i>=0;i--){
            if (digits[i] == 9){
                digits[i] = 0;
            }
            else {
                digits[i] += carry;
                carry = 0;
                break;
            }
        }

        if (carry == 0){
            return digits;
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};