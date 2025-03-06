class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int xOR=0;
        vector<int> mp(grid.size()*grid.size()+1,0);
        int repeated;
        int i=0;
        for (auto &vec:grid) {
            for (auto &val:vec) {
                i++;
                xOR = xOR ^ val ^ i;
                if (mp[val]!=0) {
                    repeated = val;
                }
                else {
                    mp[val]++;
                }
            }
        }
        return {repeated,xOR^repeated};
    }
};
