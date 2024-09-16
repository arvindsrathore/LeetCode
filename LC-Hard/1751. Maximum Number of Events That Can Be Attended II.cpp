// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/

class Solution {
public:
    vector<vector<int>> dp;
    int f(int idx,int k,vector<vector<int>>& a){
        if(k<=0 || idx>=a.size())   return 0;
        if(dp[idx][k]!=-1)  return dp[idx][k];
        int st = a[idx][0];
        int ed = a[idx][1];
        int val = a[idx][2];
        int l = idx+1,r = a.size()-1;
        int ans = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(a[m][0]>ed){
                ans = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        int x =(ans!=-1) ? val + f(ans,k-1,a) : val;
        int y = f(idx+1,k,a);
        return dp[idx][k] = max(x,y);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n = events.size();
        dp = vector<vector<int>> (n+1,vector<int>(k+1,-1));
        return f(0,k,events);
    }
};