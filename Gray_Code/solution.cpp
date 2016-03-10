class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        if (n < 0) {
            return ret;
        }
        ret.push_back(0);

        int m = 1;
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                ret.push_back(ret[j]);
                ret.back() += m;
            }
            m *= 2;
        }
        return ret;
    }
};
