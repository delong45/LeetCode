class Solution {
public:
    int addDigits(int num) {
        int total = 0;
        while (num > 0) {
            int remainder = num % 10;
            num = num / 10;
            total += remainder;
        }

        if (total < 10) {
            return total;
        }
        return addDigits(total);
    }
};
