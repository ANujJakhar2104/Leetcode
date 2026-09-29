class Solution {
public:
    map<int,string> mp_ones , mp_ten , mp_teens;
    void solve(int num, string& ans) {
        int a = num / 100;
        if (a != 0) {
            if (!ans.empty()) ans += " ";
            ans += mp_ones[a];
            ans += " Hundred";
        }

        num = num % 100;

        int b = num / 10;

        if (b != 0) {
            if (b == 1) {
                if (!ans.empty()) ans += " ";
                ans += mp_teens[num];
                return;
            } else {
                if (!ans.empty()) ans += " ";
                ans += mp_ten[b];
            }
        }

        int c = num % 10;

        if (c != 0) {
            if (!ans.empty()) ans += " ";
            ans += mp_ones[c];
        }
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero"; 
        vector<int> word(4);
        int n = num;
        int idx = 3;
        while(n > 0){
            word[idx] = n%1000;
            n /= 1000;
            idx -= 1;
        }

        mp_ones = {
            {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
            {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}
        };

        mp_ten = {
            {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"},
            {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}
        };

        mp_teens = {
            {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}
        };
        
        string ans;
        if (word[0] != 0) {
            solve(word[0] , ans);
            ans += " Billion";
        }
        if (word[1] != 0) {
            solve(word[1] , ans);
            ans += " Million";
        }
        if (word[2] != 0) {
            solve(word[2] , ans);
            ans += " Thousand";
        }
        solve(word[3] , ans);

        return ans;
    }
};