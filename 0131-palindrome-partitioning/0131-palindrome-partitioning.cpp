class Solution {
public:
    bool check(string& s, int st, int ed) {
        while (st <= ed) {
            if (s[st] != s[ed]) return false;
            st++;
            ed--;
        }
        return true;
    }

    void solve(int idx, string& s, vector<string>& temp, vector<vector<string>>& ans) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (check(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, temp, ans);
        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<string>> ans;

//     bool check(string& s, int st, int ed) {
//         while (st <= ed) {
//             if (s[st] != s[ed]) return false;
//             st++;
//             ed--;
//         }
//         return true;
//     }

//     void solve(string s) {
//         int st = 0;
//         int ed = s.size() - 1;
//         int i = st;
//         int j = ed;

//         while (i < j) {
//             vector<string> temp;
//             int mid = j - 1;
//             if (check(s, i, mid) && check(s, mid + 1, ed)) {
//                 temp.push_back(s.substr(st, mid - st + 1));
//                 temp.push_back(s.substr(mid + 1, ed - mid));
//                 ans.push_back(temp);
//                 solve(s.substr(st, mid - st + 1));
//                 solve(s.substr(mid + 1, ed - mid));
//             }
//             j--;
//         }
//     }

//     vector<vector<string>> partition(string s) {
//         solve(s);
//         vector<string> temp;
//         for (char c : s) temp.push_back(string(1, c));
//         ans.push_back(temp);
//         return ans;
//     }
// };


