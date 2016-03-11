class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        string s = "1";

        for (int i = 2; i <= n; i++) {
            string res;
            char prev = s[0];
            int count = 0;

            for (int j = 0; j < s.length(); j++) {
                if (s[j] != prev) {
                    res += (to_string(count) + prev);
                    prev = s[j];
                    count = 1;
                } else {
                    count++;
                }

                if (j == s.length()-1) {
                    res += (to_string(count) + prev);
                }
            }
            s = res;
        }
        return res;
    }
};
