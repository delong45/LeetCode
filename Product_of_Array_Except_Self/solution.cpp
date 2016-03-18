class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> n = nums;
        int left = 1;      
        int right = nums[nums.size()-1];

        for (int i = 0; i < nums.size(); i++) {
            n[i] = left;
            left *= nums[i];
        }
        for (int i = nums.size()-2; i >= 0; i--) {
            n[i] *= right;
            right *= nums[i];
        }
        return n;
    }
};
