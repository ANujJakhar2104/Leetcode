class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char , int> mp;
        int i=0 , j=0;
        int ans = 0;
        while(j < n){
            char ch = s[j];
            mp[ch] += 1;
            
            while(mp[ch] > 1){
                mp[s[i]] -= 1;
                if (mp[s[i]] == 0){
                    mp.erase(mp[s[i]]);
                }
                i++;
            }
            
            ans = max(ans , j-i+1);
            j++;
        }
        return ans;
    }
};