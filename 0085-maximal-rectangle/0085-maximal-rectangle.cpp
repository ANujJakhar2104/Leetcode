class Solution {
private:
    int solve(vector<int>& height){
        int maxa = 0;
        stack<int> st;
        int n=height.size();
        for(int i=0 ;i<=n;i++){
            while(!st.empty() && (i==n || height[st.top()] > height[i])){
                int width = 0;
                int h = height[st.top()];
                st.pop();
                if (st.empty()) width = i;
                else width = i-st.top()-1;

                maxa = max(maxa , width*h);
            }
            st.push(i);
        }
        return maxa;
    }
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int ans = 0;
        int m= mat.size();
        int n= mat[0].size();

        vector<int> height(n , 0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (mat[i][j] == '1') height[j]++;
                else height[j]=0;
            }
            ans = max(ans , solve(height));
        }

        return ans;
    }
};


// class Solution {
// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int ans = 0;
//         int m= matrix.size();
//         int n= matrix[0].size();
//         vector<vector<pair<int,int>>> dp(m,vector<pair<int,int>>(n , {0,0}));

//         for(int i=0;i<n;i++){
//             if (matrix[0][i] == '1') {
//                 dp[0][i].first =1;
//                 dp[0][i].second = 1;
//             }
//             if (i > 0 && matrix[0][i-1] == '1'){
//                 dp[0][i].second += dp[0][i-1].second;
//             }

//             ans = max(ans , dp[0][i].first * dp[0][i].second);
//         }

//         for(int i=1;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if (matrix[i][j] == '1'){
//                     dp[i][j].first = 1;
//                     dp[i][j].second = 1;

//                     if (matrix[i-1][j] == '1'){
//                         dp[i][j].first += dp[i- 1][j].first;
//                     }
//                     if (j>0 && matrix[i][j-1]=='1'){
//                         dp[i][j].second += dp[i][j-1].second;
//                     }
//                     int rows = dp[i][j].first;
//                     int idx = 0;
//                     int width = INT_MAX;
//                     while (idx!=rows){
//                         width = min(width , dp[i-idx][j].second);
//                         idx++;
//                         ans = max(ans , idx* width);
//                     }
//                     ans = max({ans,dp[i][j].first,dp[i][j].second});
//                 }
//             }
//         }

//         return ans;
//     }
// };