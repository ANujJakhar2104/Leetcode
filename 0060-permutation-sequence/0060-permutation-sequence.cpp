class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(10, 1);
        for(int i = 1; i < 10; i++){
            fact[i] = i * fact[i-1];
        }

        k--;

        string ans = "";
        vector<bool> vis(n+1, false);

        int sz = 0;

        while(sz < n){
            int block = fact[n - sz - 1];
            int skip = k / block;

            int cnt = 0;
            for(int i = 1; i <= n; i++){
                if(vis[i]) continue;

                if(cnt == skip){
                    ans.push_back('0' + i);
                    vis[i] = true;
                    sz++;
                    break;
                }
                cnt++;
            }

            k = k % block;
        }

        return ans;
    }
};