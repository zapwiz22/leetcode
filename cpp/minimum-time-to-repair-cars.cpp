class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long r = INT_MIN;
        for (auto val:ranks) r = max(r,(long long)val);
        long long l = 1;
        long long sqr = 1LL*cars*cars;
        r = r*sqr;
        long long ans = 0;
        // using binary search to find the correct time at which all the cars repairing time will be minimum
        while (l<=r) {
            long long mid = l + (r-l)/2;
            long long cnt=0;
            for (auto val:ranks) {
                cnt += (long long)(sqrt(mid/val));
            }
            if (cnt>=cars) {
                ans = mid;
                r = mid -1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
