// class Solution {
// public:
//     int minCost(string s, vector<int>& time) {
//         int ans = 0;
//         int n = s.size();
//         for(int i=1 ;i<n ;i++){
//             if (s[i] != s[i-1]){
//                 continue;
//             }
//             else {
//                 if (time[i-1] == INT_MAX){
//                     int a = i-2;
//                     while (a >= 0){
//                         if (s[i] != s[a]){
//                             break;
//                         }
//                         else if (s[i] == s[a] && (time[a] != INT_MAX)){
//                             if (time[i] < time[a]) {
//                                 ans += time[i];
//                                 time[i] = INT_MAX;
//                             }
//                             else {
//                                 ans += time[a];
//                                 time[a] = INT_MAX;
//                             }
//                             break;
//                         }
//                         a++;
//                     }
//                 }
//                 else {
//                     if (time[i] < time[i-1]) {
//                         ans += time[i];
//                         time[i] = INT_MAX;
//                     }
//                     else {
//                         ans += time[i-1];
//                         time[i-1] = INT_MAX;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.size();
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]){
                ans += min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }

        return ans;
    }
};