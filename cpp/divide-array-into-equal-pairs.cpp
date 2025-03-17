class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> mp;
        // map to check the count of every element if any element with odd count found then return false else return true
        for (auto val:nums) {
            mp[val]++;
        }
        for (auto m:mp) {
            if (m.second&1) return false;
        }
        return true;
    }
};

/* another method to solve is to sort the vector and check every 2 side by side elements to be equal after every 2 values (i.e., i+=2) if any element different found return false else return true*/
