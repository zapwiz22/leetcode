class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 0, r = *max_element(nums.begin(),nums.end());
        int ans=0;
        // binary search is used to find the approapriate value for the condition is satisfied i.e., we are able to find k houses with less than or equal to dollars
        while (l<=r) {
            int mid = l + (r-l)/2;
            int cnt = 0;
            for (int i=0;i<nums.size();i++) {
                if (nums[i]<=mid) {
                    cnt++;
                    i++;
                }
            }
            if (cnt>=k) {
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
