class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word , int idx , int x , int y){
        if (board[x][y] == word[idx] && idx == word.size() - 1) return true;

        int dx[4] = {-1 , 0 , 1 , 0};
        int dy[4] = {0 , -1 , 0 , 1};
        int row = board.size();
        int col = board[0].size();

        if (board[x][y] != word[idx]) return false;

        char temp = board[x][y];
        board[x][y]  = '%';

        for(int i = 0 ; i<4 ;i++){
            int nr = x + dx[i];
            int nc = y + dy[i];

            if (nr >= 0 && nr < row && nc>=0 && nc < col){
                if (dfs(board , word , idx+1 , nr ,nc)){
                    board[x][y] = temp;
                    return true;
                }
            }
        }
        board[x][y] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        char frt = word[0];
        int row = board.size();
        int col = board[0].size();
        stack<tuple<char , int ,int>> st;

        for(int i = 0 ; i<row ; i++){
            for(int j =0 ; j< col ; j++){
                if (board[i][j] == frt) st.push({board[i][j] , i , j});
            }
        }

        while (!st.empty()){
            auto [ch , x , y] = st.top();
            st.pop();
            if (dfs(board , word , 0 , x , y)) return true; // i did a mistake here
       }
       return false;
    }
};



// class Solution {
// public:
//     bool dfs(vector<vector<char>>& board, string word , int idx , int i , int j) {
//         if (board[i][j] == word[idx] && idx == word.size() - 1) return true;

//         int dx[4] = {-1 , 0 , 1 , 0};
//         int dy[4] = {0 , -1 , 0 , 1};
//         int row = board.size();
//         int col = board[0].size();

//         if (board[i][j] != word[idx]) return false;

//         char temp = board[i][j];
//         board[i][j] = '#';

//         for (int a = 0; a < 4; a++) {
//             int ni = i + dx[a];
//             int nj = j + dy[a];
//             if (ni >= 0 && ni < row && nj >= 0 && nj < col) {
//                 if (dfs(board, word, idx + 1, ni, nj)) {
//                     board[i][j] = temp;
//                     return true;
//                 }
//             }
//         }

//         board[i][j] = temp;
//         return false;
//     }

//     bool exist(vector<vector<char>>& board, string word) {
//         int row = board.size();
//         int col = board[0].size();
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 if (dfs(board , word , 0 , i , j)) return true;
//             }
//         }
//         return false;
//     }
// };
