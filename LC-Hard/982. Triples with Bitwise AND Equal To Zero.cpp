// https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/description/

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n=nums.size();
        int mp[1<<16];
        memset(mp,0,sizeof(mp));
        for(auto x:nums){
            for(auto y:nums){
                mp[x&y]++;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<(1<<16);j++){
                if((nums[i]&j)==0){
                    ans+=mp[j];
                }
            }
        }
        return ans;
    }
};