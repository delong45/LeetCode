class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string compare;
        if (strs.size() == 0) {
            return compare;
        }
        compare = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string prefix;
            int len = compare.size() < strs[i].size() ? compare.size() : strs[i].size();
            for (int j = 0; j < len; j++) {
                if (compare[j] != strs[i][j]) {
                    break;
                }
                prefix.append(1, strs[i][j]);
            }
            compare.clear();
            compare.append(prefix.c_str());
        }
        return compare;
    }
};
