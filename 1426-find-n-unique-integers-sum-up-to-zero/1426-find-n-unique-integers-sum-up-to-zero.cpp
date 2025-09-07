class Solution {
public:
    vector<int> sumZero(int n) {
        int one_way = n/2;
        vector<int> ans;

        for(int i=1 ; i <= one_way ; i++){
            ans.push_back(i);
            ans.push_back(-1*i);
        }

        if (n%2 == 0) return ans;
        ans.push_back(0);
        return ans; 
    }
};