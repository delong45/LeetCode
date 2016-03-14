class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int max = 0;
        for (int i = 0; i < (n+1); i++) {
            max += i;
        }
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }
        int ret = max - total;

        return ret;
    }
};
