class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int num : nums){
            mp[num] += 1;
        }

        for(auto &[num , count] : mp){
            pq.push({count , num});
        }

        while (k > 0 && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            k -= 1;
        }

        return ans;
    }
};