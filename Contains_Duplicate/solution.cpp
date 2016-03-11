class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++) {
            it = m.find(nums[i]);
            if (it != m.end()) {
                return true;
            }
            m[nums[i]] = 1;
        }
        return false;
    }
};
