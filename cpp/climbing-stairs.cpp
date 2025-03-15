class Solution {
public:
    int climbStairs(int n) {
        if (n<=2) return n;
        int prev1 = 1;
        int prev2 = 2;
        int ans = 0;
        for (int i=3;i<=n;i++) {
            // either take 1 step or 2 step forward
            ans = prev1 + prev2;
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
};
