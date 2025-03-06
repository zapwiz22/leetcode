class Solution {
public:
    long long coloredCells(int n) {
        return 1 + 4*(1LL*(n-1)*n)/2;
    }
};
