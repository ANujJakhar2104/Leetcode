class Solution {
private:
    int power(int n) {
        if (n < 3) return 0;
        return 1 + power(n / 3);
    }

public:
    bool checkPowersOfThree(int n) {
        std::vector<int> ans;
        while (n > 0) {
            int p = power(n);
            if (std::find(ans.begin(), ans.end(), p) == ans.end()) {
                ans.push_back(p);
                n -= pow(3,p);
            } else {
                return false;
            }
        }
        return true;
    }
};
