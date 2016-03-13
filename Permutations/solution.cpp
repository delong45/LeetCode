class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        if (n == 0) {
            return ret;
        }
        if (n == 1) {
            ret.push_back(nums);
            return ret;
        }

        for (int i = 0; i < n; i++) {
            vector<int> curNums = nums;
            curNums.erase(curNums.begin()+i);
            vector<vector<int>> tmp = permute(curNums);

            for (int j = 0; j < tmp.size(); j++) {
                vector<int> v = tmp[j];
                v.push_back(nums[i]);
                ret.push_back(v);
            }
        }

        return ret;
    }
};
