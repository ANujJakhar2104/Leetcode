class Solution {
public:
    int maxOperations(string s) {
        // vector<int> a(s.begin() , a.end());
        int n = s.size();
        // int zr = n-1;
        // for(int i=n-1;i>=0;i--) {
        //     if(s[i] == '0'){
        //         zr = i;
        //         break;
        //     }  
        // }
        // if (zr == 0) return 0;

        // int on = n-1;
        int ans = 0;

        int on = 0;
        if (s[0] == '1') on++;
        for(int i=1;i<n;i++){
            if (s[i] == '0' && s[i-1] == '1') {
                ans += on;
            }
            if (s[i] == '1') on++;
        }

        return ans;

    }
};