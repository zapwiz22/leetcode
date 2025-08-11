/* main logic
 * pre-compute all the multiplication stuff from beginning to end
 * then use modular inverse using fermat-little-theorem
 * to find the modular inverse of the prefix[l] to find the Solution
 */

/* more-clean logic
 * since the the range of l to r is till 32 only as powers of 2
 * we can directly run the loop from l to r instead of using modular inverse */
class Solution {
  const int MOD = 1e9 + 7;
  int inv(int n) {
    int res = 1;
    int b = MOD - 2;
    while (b > 0) {
      if (b & 1)
        res = res % MOD * 1ll * n % MOD % MOD;
      n = 1ll * n % MOD * n % MOD % MOD;
      b >>= 1;
    }
    return res % MOD;
  }

public:
  vector<int> productQueries(int n, vector<vector<int>> &queries) {
    vector<int> powers;
    for (int i = 0; i <= 31; i++) {
      if (n & (1ll << i)) {
        powers.push_back((1ll << i));
      }
    }
    vector<long long> pref(powers.size() + 1);
    vector<int> res;
    pref[0] = 1;
    for (int i = 0; i < powers.size(); i++) {
      pref[i + 1] = 1ll * pref[i] % MOD * powers[i] % MOD % MOD;
    }
    for (auto &v : queries) {
      int l = v[0], r = v[1];
      long long val = pref[r + 1] % MOD * 1ll * inv(pref[l]) % MOD % MOD;
      res.push_back(val);
    }
    return res;
  }
};
