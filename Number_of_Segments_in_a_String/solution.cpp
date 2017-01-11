class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        bool has_start = false;
        for (int i = 0; i < s.size(); i++) {
            if (has_start) {
                if (s[i] == ' ') {
                    count += 1; 
                    has_start = false;
                }
            } else {
                if (s[i] != ' ') {
                    has_start = true;
                }
            }
        }
        if (has_start) {
            count += 1;
        }
        return count;
    }
};
