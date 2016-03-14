class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1 == version2) return 0;
        vector<string> v1 = split(version1, '.');
        vector<string> v2 = split(version2, '.');
        int n = v1.size() < v2.size() ? v1.size() : v2.size();
        for (int i = 0; i < n; i++) {
            if (atoi(v1[i].c_str()) > atoi(v2[i].c_str())) {
                return 1;
            } else if (atoi(v1[i].c_str()) < atoi(v2[i].c_str())) {
                return -1;
            } else {
                continue;
            }
        }

        if (v1.size() > v2.size()) {
            for (int i = n; i < v1.size(); i++) {
                if (atoi(v1[i].c_str()) > 0) {
                    return 1;
                }
            }
        } else if (v1.size() < v2.size()) {
            for (int i = n; i < v2.size(); i++) {
                if (atoi(v2[i].c_str()) > 0) {
                    return -1;
                }
            }
        }
        return 0;
    } 

private:
    vector<string> split(const string s, char delim) {
        vector<string> v;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            v.push_back(item);
        }
        return v;
    }
};
