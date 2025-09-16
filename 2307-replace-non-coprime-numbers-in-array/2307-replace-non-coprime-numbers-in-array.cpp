class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int x : nums) {
            st.push_back(x);
            while (st.size() > 1) {
                int a = st.back(); st.pop_back();
                int b = st.back(); st.pop_back();
                int g = gcd(a, b);
                if (g > 1) {
                    st.push_back(lcm(a, b));
                } else {
                    st.push_back(b);
                    st.push_back(a);
                    break;
                }
            }
        }
        return st;
    }
};
