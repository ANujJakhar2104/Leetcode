class Solution {
private:
    void solve(vector<vector<int>>& squares , double mid , double& below , 
        double& above){
        for(auto& sq : squares){
            double y = sq[1];
            double l = sq[2];

            if (y+l <= mid) below += l*l;
            else if (y >= mid) above += l*l;
            else {
                above += l*(y+l-mid);
                below += l*(mid-y);
            }
        }
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double st = 1e18, ed = -1e18;
        for(auto& sq : squares){
            double y = sq[1];
            double l = sq[2];
            st = min(st, y);
            ed = max(ed, y + l);
        }

        while (ed - st > 1e-5){
            double mid = st + (ed-st)/2.0;
            double below = 0;
            double above = 0;
            solve(squares , mid , below , above);
            if (below >= above) ed = mid;
            else st = mid;
        }
        return st;
    }
};