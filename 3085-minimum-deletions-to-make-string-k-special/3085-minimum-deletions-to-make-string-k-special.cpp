class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> ch(26,0);
        int max_freq = INT_MIN;
        int ans = INT_MAX;
        for(char a : word){
            ch[a-'a'] += 1;
            max_freq = max(max_freq , ch[a-'a']);
        }

        for(int i=1;i<=max_freq;i++){
            int sum = 0;
            for(int j=0;j<26;j++){
                if (ch[j] == 0) continue;

                if (ch[j] < i) sum += ch[j];
                else if (ch[j] > i+k) sum +=  ch[j]-i-k;
            }
            ans = min(ans , sum);
        }
        return ans;
    }
};