class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        int i = 0;
        int last = nums.size() - 1;
        while (i < last) {
            int a = nums[i], j = i + 1, k = last;
            while (j < k) {
                int b = nums[j], c = nums[k], sum = a+b+c;
                if (sum == 0) triplets.push_back({a, b, c});
                if (sum <= 0) while (j < k && nums[j] == b) j++;
                if (sum >= 0) while (j < k && nums[k] == c) k--;
            }
            while (i < last && nums[i] == a) i++;
        }
        return triplets;
    }
};
