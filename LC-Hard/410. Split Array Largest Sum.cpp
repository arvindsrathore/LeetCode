// https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public:
    int f(vector<int>& a,int mid){
        int curr = 0;
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(curr+a[i]<=mid){
                curr+=a[i];
            }
            else{
                cnt++;
                if(a[i]<=mid)   curr=a[i];
                else    return 1e9;
            }
        }
        return cnt+1;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=0,r=1e9;
        int ans = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            int seg = f(nums,mid);
            if(seg<=k){
                ans=mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};