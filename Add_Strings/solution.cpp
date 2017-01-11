class Solution {
public:
    string addStrings(string num1, string num2) {
        bool carry = false;
        string result;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while (i >= 0 || j >= 0) {
            int n = 0;
            if (i >= 0) {
                n += (num1[i] - '0');
            }
            if (j >= 0) {
                n += (num2[j] - '0');
            }
            if (carry) {
                n += 1;
                carry = false;
            }
            if (n > 9) {
                carry = true;
                n %= 10;
            }
            string current;
            current += ('0' + n);
            result = current + result;
            i--;
            j--;
        }
        if (carry) {
            string current = "1";
            result = current + result;
        }
        return result;
    }
};
