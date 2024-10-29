class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            g = __gcd(g,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(g%nums[i]==0){
                return ans;
            }
            ans++;
        }
        return -1;
    }
};