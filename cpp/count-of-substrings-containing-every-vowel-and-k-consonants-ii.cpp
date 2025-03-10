
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int left = 0, right = 0;
        int a = 0, e = 0, i = 0, o = 0, u = 0, cons = 0;
        long long ans = 0;
        // precomputing the next constant so that at a particular left all the valid substrings are taken into account directly reducing the time complexity
        vector<int> nextConsonant(word.size());
        int nextConsonantIndex = word.size();
        for (int j = word.size() - 1; j >= 0; j--) {
            nextConsonant[j] = nextConsonantIndex;
            if (word[j] != 'a' && word[j] != 'e' && word[j] != 'i' && word[j] != 'o' && word[j] != 'u') {
                nextConsonantIndex = j;
            }
        }
        // loop to find the valid substrings
        while (right < word.length()) {
            if (word[right] == 'a') a++;
            else if (word[right] == 'e') e++;
            else if (word[right] == 'i') i++;
            else if (word[right] == 'o') o++;
            else if (word[right] == 'u') u++;
            else cons++;
            // finding valid substrings for particular k
            while (cons > k) {
                if (word[left] == 'a') a--;
                else if (word[left] == 'e') e--;
                else if (word[left] == 'i') i--;
                else if (word[left] == 'o') o--;
                else if (word[left] == 'u') u--;
                else cons--;
                left++;
            }
            // adding the valid substrings for every left till the condition is satisfied
            while (left<word.length() && a > 0 && e > 0 && i > 0 && o > 0 && u > 0 && cons == k) {
                ans += (nextConsonant[right] - right);
                if (word[left] == 'a') a--;
                else if (word[left] == 'e') e--;
                else if (word[left] == 'i') i--;
                else if (word[left] == 'o') o--;
                else if (word[left] == 'u') u--;
                else cons--;
                left++;
            }
            right++;
        }
        return ans;
    }
};
