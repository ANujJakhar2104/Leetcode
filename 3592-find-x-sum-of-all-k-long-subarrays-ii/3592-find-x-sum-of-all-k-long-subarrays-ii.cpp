class Solution {
using ll = long long;
set<pair<int,int>> main;
set<pair<int,int>> remain;
long long sum =0 ;
private:
    void addSet(pair<int,int> p ,int x) {
        auto it = *main.begin();
        if (main.size() < x || it < p){
            sum += 1LL * p.first * p.second;
            main.insert(p);

            if (main.size() > x){
                sum -= 1LL * it.first * it.second;
                main.erase(it);
                remain.insert(it);
            }
        }
        else {
            remain.insert(p);
        }
    }

    void removeSet(pair<int,int> p , int x){
        if (main.find(p) != main.end()){
            sum -= 1LL * p.first * p.second;
            main.erase(p);

            if (!remain.empty()){
                auto it = *remain.rbegin();
                sum += 1LL * it.first * it.second;
                main.insert(it);
                remain.erase(it);
            }
        }
        else {
            remain.erase(p);
        }
    }

public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<ll> ans;
        int n = nums.size();
        unordered_map<int, int> mp;
        sum = 0;

        int  i = 0, j = 0;
        while (j < n) {
            if (mp[nums[j]] > 0){
                removeSet({mp[nums[j]] , nums[j]} , x);
            }

            mp[nums[j]]++;
            addSet({mp[nums[j]] , nums[j]} , x);

            if (j - i + 1 == k) {
                ans.push_back(sum);

                removeSet({mp[nums[i]] , nums[i]} , x);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                else{
                    addSet({mp[nums[i]] , nums[i]} , x);
                }
                i++;  
            }
            j++;
        }
        return ans;
    }
};