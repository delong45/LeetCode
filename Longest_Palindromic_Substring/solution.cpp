class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }
        bool dp[1000][1000] = {0};
        int max_len = 0; 
        int len = 0;
        int pos = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if ((s[j] == s[i]) && ((i - j <= 2) || (dp[j+1][i-1]))) {
                    dp[j][i] = true;
                }
                if (dp[j][i]) {
                    len = i - j + 1;
                    if (len > max_len) {
                        max_len = len;
                        pos = j;
                    }
                }
            }
        }
        return s.substr(pos, max_len);
    }
};
