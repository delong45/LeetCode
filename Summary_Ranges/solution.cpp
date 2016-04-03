class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        if (nums.size() == 0) return result;
        
        string start = to_string(nums[0]);
        if (nums.size() == 1) {
            result.push_back(start);
            return result;
        }

        string end;
        string item;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]+1) {
                end = to_string(nums[i-1]);
                if (start != end) {
                    item = start + "->" + end;
                } else {
                    item = start;
                }
                result.push_back(item);
                start = to_string(nums[i]);
                if (i == nums.size()-1) {
                    result.push_back(start);
                }
            } else if (i == nums.size()-1) {
                end = to_string(nums[i]);
                item = start + "->" + end;
                result.push_back(item);
            }
        }
        return result;
    }
};
