// https://leetcode.com/problems/cherry-pickup-ii/

// Beats 99.13%

class Solution {
public:
    int dp[71][71][71];
    int f(int a,int b,int idx,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(idx==n)  return 0;

        if(dp[a][b][idx]!=-1)   return dp[a][b][idx];
        int best = 0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(a+i>=0 && a+i<m && b+j>=0 && b+j<m && a+i<b+j){
                    best = max(best,f(a+i,b+j,idx+1,grid));
                }
            }
        }
        return dp[a][b][idx] = grid[idx][a] + grid[idx][b] + best;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return f(0,m-1,0,grid);
    }
};