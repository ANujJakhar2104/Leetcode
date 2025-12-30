class Solution {
private:
    bool compare(string& s1 , string& s2){
        if (s1.size() != s2.size()+1) return false;

        int fst=0 , snd=0;
        while (fst < s1.size()){
            if (snd <s2.size() && s1[fst] == s2[snd]){
                fst += 1;
                snd += 1;
            }
            else {
                fst++;
            }
        }
        if (fst == s1.size() && snd==s2.size()) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string s1, string s2) {
        return s1.size() < s2.size();
        });

        int n = words.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if (compare(words[i] , words[j]) && 1+dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                }
            }
            if (dp[i] > maxi){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};