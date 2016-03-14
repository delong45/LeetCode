class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int end = n - 1;
        int max = nums[0];

        for (int pos = 1; pos <= end; pos++) {
            if (pos > max) {
                return false;
            }
            if (pos + nums[pos] > max) {
                max = pos + nums[pos];
            }
            if (max >= end) {
                return true;
            }
        }
        return true;
    }
};
