// https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/description/

class Solution {
public:
    int dp[1002][1002];
    int solve(int n,int k){
        if(k==0 || k>n)    return 0;
        if(n<=2)    return 1;
        if(dp[n][k]!=-1)    return dp[n][k];
        long long mod = 1e9+7;
        long long ans = 0;
        ans = (ans + solve(n-1,k-1))%mod;
        ans = (ans + ((n-1)%mod*solve(n-1,k)%mod)%mod)%mod;
        return dp[n][k] = ans;
    }
    int rearrangeSticks(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};