class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // finding the position of the first positive number and then calculating number of positives using (size of vector) - (this position)
        int pos = lower_bound(nums.begin(),nums.end(),1)-nums.begin();
        // the number of negatives is the same as the index of the first non-negative number since non-decreasing vector
        int neg = lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        pos = nums.size()-pos;
        return max(pos,neg);
    }
};
