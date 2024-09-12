// https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

class Solution {
public:
    int dp[201][201];
    int f(int jdx,int idx,vector<vector<int>>& grid){
        int n = grid.size();
        if(idx>=n) return 0; 
        if(jdx<0 || jdx>=n)  return 1e9;
        if(dp[jdx][idx]!=-1)    return dp[jdx][idx];
        int least = 1e9;
        for(int j=0;j<n;j++){
            if(j!=jdx){
                least = min(least,f(j,idx+1,grid));
            }
        }
        if(least == 1e9)    least = 0;
        return dp[jdx][idx] = (grid[idx][jdx] + least);
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp,-1,sizeof(dp));
        int ans = 1e9;
        for(int i=0;i<n;i++)       ans = min(ans,f(i,0,grid));
        return ans;
    }
};