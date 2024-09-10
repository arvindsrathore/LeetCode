// https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/

class Solution {
public:
    int best(int ix,int jx,vector<vector<int>> &dp){
        int mx=0;
        for(int i=ix;i<dp.size();i++){
            for(int j=jx;j<dp[0].size();j++){
                mx = max(mx,dp[i][j]);
            }
        }
        return mx;
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)    dp[i][m] = -1e6;
        for(int j=0;j<=m;j++)    dp[n][j] = -1e6;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = a[i]*b[j];
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                // int mx = best(i+1,j+1,dp);
                dp[i][j] = max({dp[i][j],dp[i][j+1],dp[i+1][j],dp[i][j] + dp[i+1][j+1]});
            }
        }
        int ans=-1e6;
        for(int i=0;i<n;i++)    ans = max(ans,dp[i][0]);
        for(int j=0;j<m;j++)    ans = max(ans,dp[0][j]);
        return ans;
    }
};