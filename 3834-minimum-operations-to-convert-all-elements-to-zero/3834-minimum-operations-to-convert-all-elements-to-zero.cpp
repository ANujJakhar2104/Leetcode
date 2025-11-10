class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > nums[i]) {
                st.pop();
            }
            if (nums[i] == 0) {
                continue;
            }
            if (st.empty() || nums[i] > st.top()) {
                st.push(nums[i]);
                ans++;
            }
        }
        return ans;
    }
};