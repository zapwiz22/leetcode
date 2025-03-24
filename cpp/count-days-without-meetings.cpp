class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // sorting the vector of vectors to get the meetings starting in ascending order
        sort(meetings.begin(),meetings.end());
        int endMxe = meetings[0][1];
        // initial ans initialization to any day skipped from day 1
        int ans = meetings[0][0]-1;
        for (int i=1;i<meetings.size();i++) {
            if (meetings[i][0]>endMxe) {
                // if gap between start and the last ended meeting then increment
                ans += meetings[i][0]-endMxe-1;
            }
            // change endMxe to keep the max ending time always
            endMxe = max(endMxe,meetings[i][1]);
        }
        // remaining days before total days 
        ans += days-endMxe;
        return ans;
    }
};
