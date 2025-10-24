// class Solution {
// public:
//     int nextBeautifulNumber(int n) {
//         if (n == 0) return 1;
//         if (n < 22) return 22;

//         string s = to_string(n);
//         int num = s[0] - '0';
        
//         string ans;
//         for (int i = 0; i < num; i++)
//             ans += to_string(num);

//         int val = stoi(ans);
//         if (val > n) return val;

//         for (int i = 1; i <= 9; i++) {
//             string temp;
//             for (int j = 0; j < i; j++)
//                 temp += to_string(i);

//             string t = ans;
//             t.insert(1, temp);

//             int insertedVal = stoi(t);
//             sort(t.begin() , t.end());
//             int sorted_val = stoi(t);
//             if (sorted_val > n) return sorted_val;
//             if (insertedVal > n) return insertedVal;
//         }

//         return stoi(ans);
//     }
// };

class Solution {
public:
    bool solve(int x){
        string s = to_string(x);
        vector<int> vec(10,0);
        for (auto i : s) vec[i-'0']++;
        for (auto i : s){
            int c = i - '0';
            if (c == 0 || vec[c] != c) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n + 1; ; i++){
            if (solve(i)) return i;
        }
    }
};