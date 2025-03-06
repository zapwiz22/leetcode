class Solution {
    public long coloredCells(int n) {
        return 1 + 4*(1L*(n-1)*n)/2; // 1L or (long)1 here acts to convert the number to long to prevent overflow
    }
}
