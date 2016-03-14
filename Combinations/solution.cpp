class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> array;
        helper(result, array, n, k, 1);
        return result;
    }

private:
    void helper(vector<vector<int>>& result, vector<int>& array, int n, int k, int start) {
        if (array.size() == k) {
            result.push_back(array);
            return;
        }
        for (int i = start; i <= n; i++) {
            array.push_back(i);
            helper(result, array, n, k, i+1);
            array.pop_back();
        }
    }
};
