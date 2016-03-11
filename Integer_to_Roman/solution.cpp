class Solution {
public:
    string intToRoman(int num) {
        string res;
        map<int, string> roman;
        roman[1] = "I";
        roman[4] = "IV";
        roman[5] = "V";
        roman[9] = "IX";
        roman[10] = "X";
        roman[40] = "XL";
        roman[50] = "L";
        roman[90] = "XC";
        roman[100] = "C";
        roman[400] = "CD";
        roman[500] = "D";
        roman[900] = "CM";
        roman[1000] = "M";

        map<int, string>::reverse_iterator it;
        for (it = roman.rbegin(); it != roman.rend(); it++) {
            int k = it->first;
            string v = it->second;
            int n = num / k;
            num = num % k;
            while (n > 0) {
                res += v;
                n--;
            }
        }

        return res; 
    }
};
