class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        int area = 0;
        int dia = 0;

        for (auto& d : dim) {
            int len = d[0];
            int wid = d[1];
            int dr = len * len + wid * wid;

            if (dr == dia) 
                area = max(area, len * wid);
            else if (dr > dia) {
                dia = dr;
                area = len * wid;
            }
        }

        return area;
    }
};
