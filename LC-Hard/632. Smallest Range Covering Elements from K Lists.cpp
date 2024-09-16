// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<int> s;
        for(auto x:nums){
            for(auto y:x)   s.insert(y);
        }
        int k=nums.size();
        vector<int> p;
        int ans = 1e9;
        for(auto x:s){
            int f=0,mx=-1e9;
            for(int i=0;i<k;i++){
                auto it = lower_bound(nums[i].begin(),nums[i].end(),x);
                if(it==nums[i].end()){
                    f=1;
                }
                else{
                    mx = max(mx,*it);
                }
            }
            if(f==0 && (mx-x)<ans){
                if(mx-x==ans){
                    if(p[0]<x)  p = {x,mx};
                }
                else{
                    p = {x,mx};
                }
                ans = mx-x;
            }
        }
        return p;
    }
};