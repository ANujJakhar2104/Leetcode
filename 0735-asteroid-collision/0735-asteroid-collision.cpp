class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        // st.push(asteroids[0]);
        // bool neg = asteroids[0] > 0 ? false : true;
        // int n = asteroids.size();
        
        // for(int i = 1 ; i< n;i++){
        //     int curr = asteroids[i];
        //     int curr_neg = curr>0 ? false:true;
        //     while (!(st.empty()) && curr_neg != neg){
        //         if (abs(curr) > abs(st.top())){}
        //     }
        // }

        for(int i=0;i<asteroids.size();i++){
            int current = asteroids[i];
            bool curr = true;

            while (!(st.empty()) && current <0 && st.top() > 0){
                if (st.top() < -current){
                    st.pop();
                    continue;
                }
                else if (st.top() == -current){
                    st.pop();
                }
                curr = false;
                break;
            }
            if (curr){
                st.push(current);
            }
        }
        
        int n = st.size();
        vector<int> ans(n);
        for(int i =n-1 ; i>=0; i--){
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
