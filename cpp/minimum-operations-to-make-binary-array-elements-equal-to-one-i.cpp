class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        // storing the count of the number of times 0 occurs that needs to be turned into 1
        for (int i=0;i<n-2;i++) {
            if (nums[i]==0) {
                nums[i]=1;
                cnt++;
                nums[i+1]^=1;
                nums[i+2]^=1;
            }
        }
        // if all numbers are not 1 then return -1 else return the count
        if (nums[n-1]==1 && nums[n-2]==1) {
            return cnt;
        }
        else {
            return -1;
        }
    }
};
