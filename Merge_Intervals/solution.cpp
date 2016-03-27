class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n < 2) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), cmp);

        vector<Interval> result;
        result.push_back(intervals[0]);
        int curIndex = 0;

        for (int i = 1; i < n; i++) {
            if (result[curIndex].end >= intervals[i].start) {
                if (result[curIndex].end < intervals[i].end) {
                    result[curIndex].end = intervals[i].end;
                }
            } else {
                result.push_back(intervals[i]);
                curIndex++;
            }
        }

        return result;
    }
private:
    static bool cmp(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
};
