class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        // pre check if it is possible to do this or not i.e., sum already less than k then exit
        long long sum = accumulate(candies.begin(),candies.end(),0ll);
        if (sum<k) return 0;
        long long l = 0,r = 1e7;
        long long ans=0;
        // binary search to search for the perfect value of candies that can be given
        while (l<=r) {
            long long mid = l + (r-l+1)/2;
            long long cnt = 0;
            for (long long val:candies) {
                cnt += val/mid;
            }
            if (cnt>=k) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid-1;
            }
        }
        return ans;
    }
};
