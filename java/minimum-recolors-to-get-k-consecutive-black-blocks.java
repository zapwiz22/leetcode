class Solution {
    public int minimumRecolors(String blocks, int k) {
        int len = blocks.length();
        // creating a prefix block to track the number of black boxes till a particular index
        int prefix[] = new int[len + 1];
        for (int i = 0; i < len; i++) {
            if (blocks.charAt(i) == 'B') {
                prefix[i + 1] = prefix[i] + 1;
            } else {
                prefix[i + 1] = prefix[i];
            }
        }
        int mne = k + 1;
        // tracking if what is the minimum number of white boxes to be coloured black in every k block range
        for (int j = k; j <= len; j++) {
            int diff = k - (prefix[j] - prefix[j - k]);
            if (diff < mne) {
                mne = diff;
            }
        }
        return mne;
    }
}
