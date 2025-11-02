// class Solution {
// public:
//     string longestPrefix(string s) {
//         string ans = "";
//         int n = s.size();
//         int i =0  , j = n-1;

//         string suff;
//         string pref;
//         while (i < n-1){
//             pref += s[i];
//             suff = s[j] + suff;

//             if (pref == suff){
//                 ans = pref;
//             }
//             i++;
//             j--;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();

        vector<int> arr(n,0);
        int i = 1;
        int maxi = 0;
        while (i < n){
            if (s[i] == s[maxi]){
                maxi++;
                arr[i] = maxi;
                i++;
            }
            else {
                if (maxi == 0){
                    arr[i] = 0;
                    i++;
                }
                else{
                    maxi = arr[maxi - 1];
                }
            }
        }

        return s.substr(0 , arr[n-1]);
    }
};