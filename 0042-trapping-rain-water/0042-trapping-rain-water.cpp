class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            left[i] = max(height[i] , left[i-1]);
            right[n-i-1] = max(height[n-i-1] , right[n-i]); 
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int curr = min(left[i] , right[i]);
            if (curr == 0) continue;
            else {
                ans += (curr - height[i]);
            }
        }
        return ans;
    }
};