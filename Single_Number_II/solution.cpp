class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int count[32] = {0};
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] >> i) & 1) {
                    count[i]++;
                }
            }
            result |= (count[i] % 3) << i;
        }
        return result;
    }
};
