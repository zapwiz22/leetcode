class Solution {
    public int numberOfSubstrings(String s) {
        int ans = 0;
        int lastPosns[] = new int[3];
        lastPosns[0]=lastPosns[1]=lastPosns[2]=-1;
        int i=0;
        while (i<s.length()) {
            int pos = s.charAt(i)-'a';
            lastPosns[pos]=i;
            // count from the starting the valid number of substrings is the number till all the 3 chars are available and the char which came first among the last occurences
            // +1 as 0 indexed
            ans += 1 + Math.min(lastPosns[0],Math.min(lastPosns[1],lastPosns[2]));
            i++;
        }
        return ans;
    }
}
