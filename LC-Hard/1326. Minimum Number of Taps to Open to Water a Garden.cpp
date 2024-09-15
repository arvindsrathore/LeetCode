// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> a(n+1);
        for(int i=0;i<=n;i++){
            a[i].first = max(0,i-ranges[i]);
            a[i].second = min(n,i+ranges[i]);
        }
        sort(a.begin(),a.end());
        int ans=0,curr=0,mx=0,i=0;
        while(i<=n){
            if(a[i].first>curr){
                if(a[i].first>mx)   return -1;
                ans++;
                curr=mx;
            }
            else{
                mx = max(mx,a[i].second);
                i++;
                if(mx>=n)   return ans+1;
            }
        }
        if(curr>=n) return ans;
        return -1;
    }
};