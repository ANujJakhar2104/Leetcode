class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxi = 0;
        int len = arr.size();
        int Maxlength = 0;

        unordered_set<int> mp(arr.begin() , arr.end());

        for (int i = 0; i < len; i++)
        {
            for(int next = i +1 ; next < len ; next++)
            {
                int curr = arr[next];
                int sum = arr[i] + arr[next];
                int length = 2;
                while(mp.find(sum) != mp.end())
                {
                    int temp = sum;
                    sum += curr;
                    curr = temp;
                    Maxlength = max(Maxlength , ++length);
                }
            }
        }

        return Maxlength;
    }
};
