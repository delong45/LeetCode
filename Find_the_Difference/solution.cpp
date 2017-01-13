class Solution {
public:
    char findTheDifference(string s, string t) {
        char start = 'a';
        for (int i = 0;i < 26; i++) {
            char target = start + i;
            int sc = count(s.begin(), s.end(), target);
            int tc = count(t.begin(), t.end(), target);
            if (sc != tc) {
                return target;
            }
        }
        return ' ';
    }
};
