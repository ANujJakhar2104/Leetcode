class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char ,int> freq;
        for(char task : tasks) freq[task]++;

        priority_queue<int> pq;
        for(auto [task , count] : freq){
            pq.push(count);
        }
        int ans = 0;
        while (!pq.empty()){
            vector<int> temp; // ek baar repition main use krke isme daal de
            int used = 0; 
            for(int i = 0; i <= n; i++){
                if (!pq.empty()){ // agar used krke empty ho gya to baaki ke n+1 main idle
                    used += 1;
                    int curr = pq.top();
                    pq.pop();
                    if (curr > 1) temp.push_back(curr - 1);
                }
            }
            for(int t : temp) pq.push(t); // ab vaapis ushe heap main daalde

            if (!pq.empty()) {  // agar pq ab bhi empty h to aage idle use krne ki jarurat 
                ans += n + 1;   // nhi h
            }
            else ans += used;
        }
        return ans;
    }
};
