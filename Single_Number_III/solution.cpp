class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret;
        map<int, int> m;
        map<int, int>::iterator it;

        for (int i = 0; i < nums.size(); i++) {
            it = m.find(nums[i]);
            if (it == m.end()) {
                m[nums[i]] = 1;
            } else {
                m[nums[i]]++;
            }
        }
        for (it = m.begin(); it != m.end(); it++) {
            if (it->second == 1) {
                ret.push_back(it->first);
            }
        }

        return ret;
    }
};
