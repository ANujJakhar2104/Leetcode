class Solution {
public:
    int n,m;
    bool isMagicSquare(int x, int y, int &side, vector<vector<int>>& grid){
        int sum = -1;
        for(int i=x;i< (x+side);i++){
            int rowSum = 0;
            for(int j=y; j< (y+side);j++){
                rowSum += grid[i][j];
            }
            if(sum == -1) sum = rowSum;
            if(rowSum != sum) return 0;
        }

        for(int j=y;j<(y+side);j++){
            int colSum = 0;
            for(int i=x;i<(x+side);i++){
                colSum += grid[i][j];
            }
            if(colSum != sum) return 0;
        }

        int leftDiagonal = 0;
        int rightDiagonal = 0;
        for(int push=0;push<side;push++){
            leftDiagonal += grid[x+push][y+push];
            rightDiagonal += grid[x+side-1-push][y+push];
        }

        if((rightDiagonal != sum) || (leftDiagonal != sum)) return 0;

        return 1;
    }

    bool isPossible(vector<vector<int>>& grid, int &side){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i+side > n || j+side > m) continue;
                if(isMagicSquare(i,j,side,grid)) return 1;
            }
        }
        return 0;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxSide = 1;
        for(int side=2;side<=min(n,m);side++){
            if(isPossible(grid,side)){
                maxSide = side;
            }
        }
        return maxSide;
    }
};