class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> xdir, ydir;
        // creating the x and y endpoints and start of rectangles vectors 
        for (auto &vec:rectangles) {
            xdir.emplace_back(vec[0],vec[2]);
            ydir.emplace_back(vec[1],vec[3]);
        }
        // sorting to find out rectangles which are aside
        sort(xdir.begin(),xdir.end());
        sort(ydir.begin(),ydir.end());
        bool ok1 = false, ok2 = false; // one for horizontal and one for vertical
        int endMax = -1; // keeps the last ending point of rectangle till that index so to decide whether to include that rectangle only if it starts after the endPoint
        int cnt = 0;
        for (auto &pr:xdir) {
            if (pr.first >= endMax) {
                cnt++;
            }
            endMax = max(endMax,pr.second);
        }
        if (cnt>=3) ok1 = true;
        endMax = -1;
        cnt = 0;
        for (auto &pr:ydir) {
            if (pr.first>=endMax) {
                cnt++;
            }
            endMax = max(endMax,pr.second);
        }
        if (cnt>=3) ok2 = true;
        // if in any found rectangles more than 3 such that the start is after the max end found till now then return true else false
        if (ok1 or ok2) return true;
        else return false;
    }
};
