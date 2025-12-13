class Solution {
private:
    bool isall(string a) {
        for (char ch : a) {
            if (isalnum(ch) || ch == '_') continue;
            else return false;
        }
        return true;
    }

public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        
        int n = code.size();
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>>
        > pq;

        for (int i = 0; i < n; i++) {
            string s = businessLine[i];
            if (isActive[i]) {
                if (code[i] != "" && s != "invalid" && isall(code[i])) {
                    if (s == "electronics") pq.push({0, code[i]});
                    else if (s == "grocery") pq.push({1, code[i]});
                    else if (s == "pharmacy") pq.push({2, code[i]});
                    else if (s == "restaurant") pq.push({3, code[i]});
                }
            }
        }

        vector<string> ans;
        int i = -1;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
