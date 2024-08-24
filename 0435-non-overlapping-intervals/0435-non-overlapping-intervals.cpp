class Solution 
{
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int c = 0;
        sort(intervals.begin(), intervals.end(), compare);
        int lastEnd = intervals[0][1];
        for (int i = 1; i < n; i++) 
        {
            if (intervals[i][0] < lastEnd) 
            {
                c++;
            } 
            else 
            {
                lastEnd = intervals[i][1];
            }
        }
        return c;
    }
};
