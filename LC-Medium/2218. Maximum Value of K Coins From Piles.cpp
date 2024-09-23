// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& a, int k) {
        int n = a.size();
        for(auto &x:a){
            int t = 0;
            for(auto &y:x){
                y = t+y;
                t=y;
            }
        }
        vector<vector<int>> piles(n);
        for(int i=0;i<n;i++){
            piles[i].push_back(0);
            for(auto y:a[i]){
                piles[i].push_back(y);
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(2002,0));
        for(int i=0;i<n;i++){
            int m = piles[i].size();
            if(i==0){
                for(int j=0;j<m;j++){
                    dp[i][j] = piles[i][j];
                }
            }
            else{
                for(int j=0;j<=k;j++){
                    if(j==0)    dp[i][j] = max(dp[i][j],dp[i-1][j]);
                    else dp[i][j] = max(dp[i][j],max(dp[i][j-1], dp[i-1][j]));
                }
                for(int j=0;j<=k;j++){
                    for(int l=0;l<m;l++){
                        if(j+l<=2000)dp[i][j+l] = max(dp[i][j+l],piles[i][l]+dp[i-1][j]);
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};