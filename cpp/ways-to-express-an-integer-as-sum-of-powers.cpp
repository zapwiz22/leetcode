class Solution {
  const int MOD = 1e9 + 7;
  long long bin(int a, int b) {
    long long res = 1;
    while (b > 0) {
      if (b & 1)
        res = res % MOD * 1ll * a % MOD % MOD;
      a = a % MOD * 1ll * a % MOD % MOD;
      b >>= 1;
    }
    return res;
  }

public:
  int numberOfWays(int n, int x) {
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int j = 1; j <= n; j++) {
      long long val = bin(j, x);
      if (val > n)
        break;
      for (int i = n; i >= j; i--) {
        if (val <= i) {
          dp[i] = (dp[i] % MOD + dp[i - val] % MOD) % MOD;
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      cout << dp[i] << " ";
    }
    cout << endl;
    return dp[n];
  }
};
