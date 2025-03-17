class Solution {
    public boolean divideArray(int[] nums) {
        // method to sort and then check every pair to have equal values else return false
        Arrays.sort(nums);
        for (int i=0;i<nums.length;i+=2) {
            if (nums[i]!=nums[i+1]) return false;
        }
        return true;
    }
}

/* another method is to keep the count of every element in freq array since n<=500 and then if any number with odd count return false else return true */
