// https://leetcode.com/problems/minimum-cost-for-cutting-cake-ii/description/

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        long long ans = 0;
        int l=m-2,r=n-2;
        int vi=1,hi=1;
        while(l>=0 && r>=0){
            if(h[l]>=v[r]){
                ans+=h[l]*vi;
                hi++;
                l--;
            }
            else{
                ans+=v[r]*hi;
                vi++;
                r--;
            }
        }
        while(l>=0){
            ans+=h[l]*vi;l--;
        }
        while(r>=0){
            ans+=v[r]*hi;r--;
        }
        return ans;
    }
};