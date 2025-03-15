class Solution {
    public int minCapability(int[] nums, int k) {
        // method to get the max and min element directly 
        // int l = Arrays.stream(nums).min().getAsInt(), r = Arrays.stream(nums).max().getAsInt();
        int l = 1000000, r = 0;
        for (int x:nums) {
            l = Math.min(l,x);
            r = Math.max(r,x);
        }
        int ans=0;
        // binary search to find the maximum of minimum capacity after robbing k houses 
        // checking for different values whether it is possible or not and then doing approapriate shortening of range till we get the answer
        while (l<=r) {
            int mid = l + (r-l)/2;
            int cnt = 0;
            for (int i=0;i<nums.length;i++) {
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
}
