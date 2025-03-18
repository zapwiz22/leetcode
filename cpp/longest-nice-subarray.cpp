class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int ans = 1;
        // using sliding window approach to take in account which bit positions are currently used and if a new number at right requires a bit which is already set left is moved and ans is kept on updating
        int bitmask = 0;
        while (right<nums.size()) {
            while (left<right && (bitmask & nums[right])!=0) {
                // removing the already set bit by removing numbers from left 
                bitmask ^= nums[left];
                left++;
            }
            // including the numbers in the right when the bits are not set
            bitmask|=nums[right];
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
