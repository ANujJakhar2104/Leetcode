class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void solve(vector<int>& cand,int idx, int sum, int target
    , vector<int>& temp){
        if (sum == target){
            ans.push_back(temp);
            return;
        }
        if (sum > target) return;
        if (idx == n) return;
        for(int i=idx;i<n;i++){
            if (i > idx && cand[i] == cand[i-1]) continue;
            if (sum + cand[i] > target) break;
            temp.push_back(cand[i]);
            solve(cand , i+1 , sum + cand[i] , target, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        n = cand.size();
        vector<int> temp;
        sort(cand.begin(), cand.end());
        solve(cand , 0 , 0 , target , temp);
        return ans;
    }
};