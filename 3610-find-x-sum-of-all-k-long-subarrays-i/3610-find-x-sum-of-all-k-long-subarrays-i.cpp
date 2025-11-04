class Solution {
private:
    void solve(int &temp, unordered_map<int, int> &mp, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto &it : mp) {
            pq.push({it.second, it.first});
            if (pq.size() > x)
                pq.pop();
        }

        int count = 0;
        while (count < x && !pq.empty()) {
            temp += (pq.top().second) * (pq.top().first);
            pq.pop();
            count++;
        }
    }

public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mp;

        int i = 0, j = 0;
        while (j < n) {
            mp[nums[j]]++;
            if (j - i + 1 == k) {
                int temp = 0;
                solve(temp, mp, x);
                ans.push_back(temp);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
