class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n > 0) {
            return !(1162261467 % n);
        }
        return false;
    }
};
