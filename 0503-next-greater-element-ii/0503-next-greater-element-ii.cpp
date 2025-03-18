class Solution {
// private:
//     int find(stack<int> m, int digit) {
//         if (m.empty()) return -1;
//         if (m.top() > digit) return m.top();
//         m.pop();
//         return find(m, digit);
//     }
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> s;
    int n = nums.size();
    vector<int> ans(n, -1);

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums[i % n]) {
            s.pop();
        }
        if (i < n) {
            if (!s.empty()) {
                ans[i % n] = s.top();
            }
        }
        s.push(nums[i % n]);
    }
    
    return ans;
    }
};
