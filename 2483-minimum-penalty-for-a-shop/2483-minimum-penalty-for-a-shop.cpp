class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> temp_true(n, 0);
        vector<int> temp_false(n, 0);

        for (int i = 0; i < n; i++) {
            int j = n - 1 - i;

            temp_false[i] = (customers[i] == 'N');
            if (i > 0)
                temp_false[i] += temp_false[i - 1];

            temp_true[j] = (customers[j] == 'Y');
            if (j < n - 1)
                temp_true[j] += temp_true[j + 1];
        }

        int mini = temp_true[0];
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int curr = 0;
            if (i < n)
                curr += temp_true[i];
            if (i > 0)
                curr += temp_false[i - 1];

            if (curr < mini) {
                mini = curr;
                ans = i;
            }
        }

        return ans;
    }
};
