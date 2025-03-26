class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nums.push_back(grid[i][j]);
            }
        }
        // if remainder for all is not same then only -1 as they can't be made same by adding or subtracting x any number of times
        int rem = nums[0] % x;
        for (int num : nums) {
            if (num % x != rem)
                return -1;
        }
        sort(nums.begin(), nums.end());
        // finding the median as this would be the closest from both the ends
        int median = nums[nums.size() / 2];
        int operations = 0;
        for (int num : nums) {
            operations += abs(num - median) / x;
        }
        return operations;
    }
};
