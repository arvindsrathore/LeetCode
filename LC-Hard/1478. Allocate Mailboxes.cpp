// https://leetcode.com/problems/allocate-mailboxes/description/

class Solution {
public:
    int dp[101][101][101];
    int f(int idx,int prev,int k,vector<int>& houses){
        if(k<=0 && idx>=houses.size())    return 0;
        if(k<=0 || idx==houses.size())  return 1e9;
        if(dp[idx][prev][k]!=-1)    return dp[idx][prev][k];
        int mid = (idx+prev)/2;
        int place = houses[mid];
        int val = 0;
        for(int i=prev;i<=idx;i++)  val+=abs(houses[mid]-houses[i]);
        int ans = f(idx+1,prev,k,houses);
            ans = min(ans,val + f(idx+1,idx+1,k-1,houses));
        return dp[idx][prev][k] = ans;
    }
    int minDistance(vector<int>& houses, int k) {
        memset(dp,-1,sizeof(dp));
        int n=houses.size();
        sort(houses.begin(),houses.end());
        return f(0,0,k,houses);
    }
};