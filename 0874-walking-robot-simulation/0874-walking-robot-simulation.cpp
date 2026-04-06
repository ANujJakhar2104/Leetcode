class Solution {
public:
    int find(int x , int y){
        return x*x + y*y;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x =0 , y=0;
        set<pair<int,int>> st;
        for(auto &obs : obstacles){
            st.insert({obs[0] , obs[1]});
        }

        int curr = 0;
        int maxi = 0;

        for(int com : commands){
            if (com == -2){
                curr += 270;
            }
            else if (com == -1){
                curr += 90; 
            }
            else {
                int steps = com;
                curr %= 360;
                if (curr == 0){
                    while (steps--){
                        if (st.count({x, y+1})) break;
                        y += 1;
                        maxi = max(maxi , find(x,y));
                    }
                }
                else if (curr == 90) {
                    while (steps--){
                        if (st.count({x+1, y})) break;
                        x += 1;
                        maxi = max(maxi , find(x,y));
                    }
                }
                else if (curr == 180){
                    while (steps--){
                        if (st.count({x, y-1})) break;
                        y -= 1;
                        maxi = max(maxi , find(x,y));
                    }
                }
                else {
                    while (steps--){
                        if (st.count({x-1, y})) break;
                        x -= 1;
                        maxi = max(maxi , find(x,y));
                    }
                }
            }
        }

        return maxi;
    }
};