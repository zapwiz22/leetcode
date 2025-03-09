class Solution {
   public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // to push the first k-1 elements at the end to check for the last element whether k alternating blocks exist or not
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }
        int cnt = 1, ans = 0;
        int n = colors.size();
        for (int i = 1; i < n; i++) {
            if (colors[i] != colors[i - 1]) {
                cnt++;
            } else {
                if (cnt >= k) ans += (cnt - k + 1);
                cnt = 1;
            }
        }
        // statement used within loop and here to increment ans with (cnt-k+1) if k or more blocks are found with alternating elements
        if (cnt >= k) ans += (cnt - k + 1);
        return ans;
    }
};
