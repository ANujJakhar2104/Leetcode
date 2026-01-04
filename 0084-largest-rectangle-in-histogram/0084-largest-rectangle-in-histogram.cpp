class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxa = 0;
        stack<int> st;
        int n=heights.size();
        for(int i=0 ;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()] > heights[i])){
                int width = 0;
                int h = heights[st.top()];
                st.pop();
                if (st.empty()) width = i;
                else width = i-st.top()-1;

                maxa = max(maxa , width*h);
            }
            st.push(i);
        }
        return maxa;
    }
};