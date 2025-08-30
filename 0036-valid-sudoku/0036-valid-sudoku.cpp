class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int , vector<char>> row;
        unordered_map<int , vector<char>> col;
        unordered_map<int , vector<char>> bx;

        for(int i =0 ; i <9 ; i++) {
            for(int j =0 ; j < 9 ; j++){
                if (board[i][j] != '.'){
                    char val = board[i][j];
                    int box = i/3 * 3 + j/3;

                    if (find(row[i].begin(), row[i].end(), val) == row[i].end()){
                        row[i].push_back(val);
                    }
                    else return false;

                    if (find(col[j].begin(), col[j].end(), val) == col[j].end()){
                        col[j].push_back(val);
                    }
                    else return false;

                    if (find(bx[box].begin(), bx[box].end(), val) == bx[box].end()){
                        bx[box].push_back(val);
                    }
                    else return false;
                }
            }
        }

        return true;
    }
};