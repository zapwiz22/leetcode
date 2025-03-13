class Solution {
private:
    // function to check if the queries till mid value will be able to make the nums vector zero
    bool isRight(vector<int>& nums,vector<int> &prefix) {
        for (int i=0;i<nums.size();i++) {
            int val = nums[i]-prefix[i];
            if (val>0) {
                return false;
            }
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0, r = queries.size();
        int ans = -1;
        // binary search to find the mid value and then check whether the queries till there will be able to get a zero-array
        while (l<=r) {
            int mid = l + (r-l)/2;
            // prefix sum to efficiently calculate the changes till ith query
            // the first is incremented by the val and the last index + 1 is decremented by the val so that while calculating prefix sum the range is incremented by k and no other value is affected since the -val at last index + 1 will make for it
            vector<int> prefix(nums.size()+1,0);
            for (int i=0;i<mid;i++) {
                prefix[queries[i][0]]+=queries[i][2];
                prefix[queries[i][1] + 1]-=queries[i][2];
            }
            for (int i=1;i<prefix.size();i++) {
                prefix[i]+=prefix[i-1];
            }
            if (isRight(nums,prefix)) {
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
};
