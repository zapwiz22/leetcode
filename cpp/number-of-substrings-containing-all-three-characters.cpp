class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0 , right = 0;
        int a=0,b=0,c=0;
        int ans = 0;
        // using sliding window 
        while (right<s.length()) {
            if (s[right]=='a') a++;
            else if (s[right]=='b') b++;
            else if (s[right]=='c') c++
            while (a>=1 and b>=1 and c>=1) {
                // if valid condition found count all substrings from that position to the end of the string
                if (a>0 and b>0 and c>0) {
                    ans += s.length()-right;
                }
                // move left to reduce the substring and find new ones
                if (s[left]=='a') a--;
                else if (s[left]=='b') b--;
                else if (s[left]=='c') c--;
                left++;
                // if any letter count reduces below one break to incresae right and again find a valid condition 
                if (a<1 or b<1 or c<1) {
                    break;
                }
            }
            right++;
        }
        return ans;
    }
};
