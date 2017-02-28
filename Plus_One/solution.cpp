class Solution{
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = false;
        for (int i = digits.size()-1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
                carry = true;
            } else {
                digits[i]++;
                if (carry) carry = false;
                break;
            }
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};
