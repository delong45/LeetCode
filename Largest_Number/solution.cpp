class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;

        int found = false;
        for (auto i : nums) {
            if (i > 0) {
                found = true;
                break;
            }
        }
        if (!found) {
            return "0";
        }

        transform(nums.begin(), nums.end(), back_inserter(v), [](int i) {return to_string(i);});
        sort(v.begin(), v.end(), compareString);

        string r = "";
        for (auto& item : v) {
            r = r + item;
        }
        return r;
    }

    static bool compareString(const string& s1, const string& s2) {
        auto i = s1.begin();
        auto j = s2.begin();
        while (i < s1.end() && j < s2.end()) {
            if (*i != *j) {
                return *i > *j;
            }
            i++, j++;
        }

        return s1 + s2 > s2 + s1;
    }
};
