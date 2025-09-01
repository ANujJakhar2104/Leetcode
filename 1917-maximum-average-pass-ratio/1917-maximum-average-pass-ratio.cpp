class Solution {
public:
    double gain(int a , int b){
        double upper = (double)(a+1)/(b+1);
        double lower = (double)a/b;
        return upper - lower;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;

        for (int i = 0; i < classes.size(); i++) {
            pq.push({gain(classes[i][0], classes[i][1]), i});
        }

        while (extraStudents--) {
            auto [g, idx] = pq.top();
            pq.pop();

            classes[idx][0]++;
            classes[idx][1]++;

            pq.push({gain(classes[idx][0], classes[idx][1]), idx});
        }

        double ans = 0;
        for (auto& c : classes) {
            ans += (double)c[0] / c[1];
        }

        return ans / classes.size();
    }
};
