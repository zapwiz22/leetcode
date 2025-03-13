class Solution {
    public int minZeroArray(int[] nums, int[][] queries) {
        int sum = 0, k = 0;
        int n = nums.length;
        // prefix sum to calculate the changes using queries efficiently by increasing it with val at max(l,i) and decrementing at (r+1) so that the prefix is balanced after r and changes are made only in the range l to r 
        int prefix[] = new int[n+1];
        // for every index checking whether the prefix sum that is sum at the current index is sufficient or not
        for (int i=0;i<n;i++) {
            while ((sum+prefix[i])<nums[i]) {
                // queries weren't sufficient so return -1
                if (k==queries.length) return -1;
                int l = queries[k][0],r = queries[k][1], val = queries[k][2];
                k++;
                if (r<i) continue;
                // changing the prefix sum as stated above
                prefix[Math.max(l,i)]+=val;
                prefix[r+1]-=val;
            }
            // making changes to sum to check for every index is sufficient or not
            sum+=prefix[i];
        }
        return k;
    }
}
