class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        nums.insert(nums.begin(), nums.begin()+n-k%n, nums.end());
        nums.erase(nums.end()-k%n, nums.end());
    }
};
