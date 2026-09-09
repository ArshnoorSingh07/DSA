class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int>temp = intervals[0];
        int i = 0;
        int n = intervals.size();
        vector<vector<int>>mergedIntervals;
        
        while(i < n)
        {
            if(intervals[i][0] <= temp[1]){
                temp[1] = max(intervals[i][1], temp[1]);
            }
            else{
                mergedIntervals.push_back(temp);
                temp = intervals[i];
            }
            i++;
        }
        mergedIntervals.push_back(temp);
        return mergedIntervals;
    }
};