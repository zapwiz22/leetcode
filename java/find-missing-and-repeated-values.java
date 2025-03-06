
import java.util.HashSet;

class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        HashSet<Integer> seen = new HashSet<>();
        int repeated = -1, missing = -1;
        for (int[] arr : grid) {
            for (int val : arr) {
                if (seen.contains(val)) {
                    repeated = val; 
                } else {
                    seen.add(val);
                }
            }
        }
        for (int i = 1; i <= n * n; i++) {
            if (!seen.contains(i)) {
                missing = i;
                break;
            }
        }
        return new int[]{repeated, missing};
    }
}
