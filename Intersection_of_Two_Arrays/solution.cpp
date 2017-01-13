class Solution {
public:
    vector<int> intersection(vector<int>& num1, vector<int>& num2) {
        vector<int> ret;
        sort(num1.begin(), num1.end());
        sort(num2.begin(), num2.end());
        int i = 0, j = 0;
        while (i < num1.size() && j < num2.size()) {
            if (num1[i] < num2[j]) {
                i++;
            } else if (num1[i] > num2[j]) {
                j++;
            } else {
                int n = num1[i];
                ret.push_back(n);
                i++;
                j++;
                while (num1[i] == n && i < num1.size()) i++;
                while (num2[j] == n && j < num2.size()) j++;
            }
        }
        return ret;
    }
};
