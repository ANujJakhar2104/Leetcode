class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int odd = INT_MAX;
        int ev = 0;
        for (int num : nums){
            if (num&1) odd = min(odd , num);
            else ev += 1;
        }

        if (ev == n || ev == 0) return true;
        
        bool first = true;
        // odd bnate h to even main se min odd minus
        for(int num : nums){
            if (num%2 == 0){
                if (num-odd < 1){
                    first = false;
                    break;
                }
            }
        }

        bool second = true;
        // even bnate to odd main se min odd minus
        for(int num : nums){
            if (num%2 == 0){
                if (num-odd < 1){
                    second = false;
                    break;
                }
            }
        }

        return first | second;
    }
};