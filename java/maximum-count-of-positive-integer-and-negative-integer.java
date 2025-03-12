class Solution {
    public int maximumCount(int[] nums) {
        int len = nums.length;
        // using binary search to find the index of the first non-negative number i.e., l and that would be the answer
        int l = 0,r = len;
        while (l<r) {
            int mid = l + (r-l)/2;
            if (nums[mid]>=0) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        int neg = l;

        // using binary search to find the first index of positive number i.e., l and then len - l would be the answer
        l = 0;
        r = len;
        while (l<r) {
            int mid = l + (r-l)/2;
            if (nums[mid]>0) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        int pos = len - l;

        // max of these two would be the answer
        return Math.max(neg,pos);
    }
}
