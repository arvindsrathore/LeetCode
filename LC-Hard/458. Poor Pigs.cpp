// https://leetcode.com/problems/poor-pigs/description/

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int ans = ceil(log2(buckets) / log2(int(minutesToTest/minutesToDie)+1));        
        return ans;
    }
};