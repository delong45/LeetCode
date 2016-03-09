class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1) return;

        int zero_num = 0;
        vector<int>::iterator it;
        for (it = nums.begin(); it != nums.end(); it++) {
            while (*it == 0 && it != nums.end()-1)  {
                nums.erase(it);
                zero_num++;
            }
        }

        for (int i = 0; i < zero_num; i++) {
            nums.push_back(0);
        }
    }
};
