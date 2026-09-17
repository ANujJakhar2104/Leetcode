class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> sz(n + 1, 1e9);
        int i = 0;
        int sum = 0, best = 1e9, ans = 1e9;

        for (int j = 0; j < n; j++) {
            sum += arr[j];

            while (sum > target) {
                sum -= arr[i];
                i += 1;
            }

            if (sum == target) {
                int curr = j - i + 1;

                if (i > 0 && sz[i-1] != 1e9){
                    ans = min(ans , curr + sz[i-1]);
                }
                best = min(best , curr);
            }

            sz[j] = best;
        }
        return ans >= 1e9 ? -1 : ans;
    }
};

    // class Solution {
    // public:
    //     int n;
    //     vector<vector<long long>> dp;
    //     int solve(int i , int j , long long sum ,int target ,vector<int>&
    // temp     ,vector<int>& arr){         if (j >= n) {             if
    // (temp.size() < 2) return 1e9;

    //             vector<int> a = temp;
    //             sort(a.begin() , a.end());
    //             return a[0]+a[1];
    //         }
    //         if (dp[i][j] != -1) return dp[i][j];

    //         int skip = solve(i+1 , i+1 , 0 ,target, temp,arr);
    //         int n_skip = 1e9;
    //         sum += arr[j];
    //         if (sum > target){
    //             n_skip = min(n_skip , solve(i+1 , i+1 , 0 ,target
    // ,temp,arr));         }else if (sum == target){            
    // temp.push_back(j-i+1);             n_skip = min(n_skip , solve(j+1 , j+1
    // , 0 ,target, temp,arr));             temp.pop_back();         }else {    
    //         n_skip = min(n_skip , solve(i ,j+1 , sum ,target, temp,arr));    
    //     }

    //         return dp[i][j] = min(skip , n_skip);
    //     }
    //     int minSumOfLengths(vector<int>& arr, int target) {
    //         n = arr.size();
    //         dp.assign(n, vector<long long>(n, -1));
    //         vector<int> temp;
    //         int ans = solve(0, 0, 0, target, temp, arr);
    //        
    //         return ans >= 1e9 ? -1 : ans;

    //         // vector<int> sz;
    //         // int i=0,j=0;
    //         // long long sum = 0;
    //         // while (j < n){
    //         //     sum += arr[j];
    //         //     if (sum == target){
    //         //         sz.push_back(j-i+1);
    //         //         sum = 0;
    //         //         i = j+1;
    //         //         j = i;
    //         //     }else if (sum > target){
    //         //         sum = 0;
    //         //         i = i+1;
    //         //         j = i;
    //         //     }else{
    //         //         j += 1;
    //         //     }
    //         // }
    //         // if (sz.size() < 2) return -1;
    //         // sort(sz.begin() , sz.end());

    //         // return sz[0]+sz[1];
    //     }
    // };