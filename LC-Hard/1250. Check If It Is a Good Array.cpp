// https://leetcode.com/problems/check-if-it-is-a-good-array/description/

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            if(nums[0]==1)  return true;
            return false;
        }
        int g=nums[0];
        for(int i=1;i<n;i++)    g=__gcd(nums[i],g);
        if(g>1) return false;
        return true;
    }
};