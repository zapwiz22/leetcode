class Solution {
   public:
    vector<int> closestPrimes(int left, int right) {
        // creating the sieve of prime numbers and pushing all the prime numbers in a vector
        long long int N = 1000010;
        vector<bool> sieve(N, 1);
        sieve[0] = sieve[1] = false;
        vector<long long int> primeFactors;
        for (long long int i = 2; i < sieve.size(); i++) {
            if (sieve[i]) {
                primeFactors.push_back(i);
                for (long long int j = i * i; j < sieve.size(); j += i) {
                    sieve[j] = false;
                }
            }
        }
        // using lower_bound and upper_bound to find the range of prime numbers between left and right
        auto itLeft =
            lower_bound(primeFactors.begin(), primeFactors.end(), left);
        auto itRight =
            --(upper_bound(primeFactors.begin(), primeFactors.end(), right));
        // loop to get the lowest difference prime numbers 
        long long int ans = 10000000;
        int l = -1, r = -1;
        for (auto it = itLeft; it < itRight; it++) {
            long long int left = *it;
            long long int right = *(it + 1);
            if ((right - left) < ans) {
                ans = right - left;
                l = left;
                r = right;
            }
        }
        return {l, r};
    }
};
