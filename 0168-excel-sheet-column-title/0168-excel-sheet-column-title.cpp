class Solution {
    const char getAlpha(const int num) {
        return 'A' + num;
    }

public:
    string convertToTitle(int number) {
        string result;

        while (number > 0) {
            number--;
            int remainder = number % 26;
            result = getAlpha(remainder) + result;
            number /= 26;
        }

        return result;
    }
};
