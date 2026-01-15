class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        sort(hBars.begin() , hBars.end());
        sort(vBars.begin() , vBars.end());
        int ver = 1;
        int hor = 1;

        int curr = 1;
        for(int i=1;i<hBars.size();i++){
            if (hBars[i] == hBars[i-1]+1){
                curr += 1;   
            }
            else {
                curr =1;
            }
            hor = max(hor , curr);
        }

        curr = 1;
        for(int i=1;i<vBars.size();i++){
            if (vBars[i] == vBars[i-1]+1){
                curr += 1;   
            }
            else {
                curr =1;
            }
            ver = max(ver , curr);
        }
        int side = min(hor , ver) +1;
        return side * side;
    }
};