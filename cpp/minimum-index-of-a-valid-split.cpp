class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // finding the dominant number by frequency
        map<long long, long long> reverseFreq;
        for (auto &val:nums) reverseFreq[val]++;

        long long mxe = LLONG_MIN;
        long long num = -1;
        for (auto &m:reverseFreq) {
            if (m.second>mxe) {
                mxe = m.second;
                num = m.first;
            }
        }
        // for every value checking the count of the dominant specie and if it's frequency is greater than half of the number of elements in that part then that is the index
        map<long long,long long> straight;
        for (int i=0;i<nums.size();i++) {
            long long val = nums[i];
            reverseFreq[val]--;
            straight[val]++;
            if (straight[num]>((i+1)/2) and reverseFreq[num]>((nums.size()-i-1)/2)) {
                return i;
            }
        }
        return -1;
    }
};
