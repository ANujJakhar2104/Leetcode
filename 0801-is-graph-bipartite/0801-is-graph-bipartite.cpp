class Solution {
int n;
private:
bool dfs(int curr , int clr , int color[] , vector<vector<int>>& graph){
    color[curr] = clr;

    for(auto it: graph[curr]){
        if (color[it] == -1){
        if (dfs(it , !clr , color ,graph) == false) return false;
        }
        else if (color[it] == clr){
            return false;
        }
    }
    return true;
}
public:
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        int color[n];
        for(int i =0; i<n;i++) color[i] = -1;

        for(int i = 0 ; i <n ;i++){
            if (color[i] == -1){
                if (dfs(i , 0 , color , graph) == false) return false;
            }
        }
        return true;
    }
};