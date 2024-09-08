// https://leetcode.com/problems/cherry-pickup/description/

class Solution {
public:
    bool valid(int p,int q,int r,int s,int n){
        if(p<0 || p>=n) return 0;
        if(q<0 || q>=n) return 0;
        if(r<0 || r>=n) return 0;
        if(s<0 || s>=n) return 0;
        return true;
    }
    static constexpr int N = 51;
    int dp[N][N][N];
    int dfs(int p,int q,int r,vector<vector<int>>& grid){
        int n=grid.size();
        int s = p+q-r;

        if(!valid(p,q,r,s,n) || grid[p][q]==-1 || grid[r][s]==-1)   return -1e9;
        
        if(dp[p][q][r]!=-1)  return dp[p][q][r];

        if(p==n-1 && q==n-1 && r==n-1 && s==n-1)    return grid[p][q];
        
        int value = (p==r && q==s) ? grid[p][q] : grid[p][q]+grid[r][s];

        int ans = value + max({
        dfs(p,q+1,r,grid),
        dfs(p+1,q,r,grid),
        dfs(p,q+1,r+1,grid),
        dfs(p+1,q,r+1,grid)
        });
        // cout<<p<<" "<<q<<"  "<<r<<" "<<s<<"  "<<ans<<"\n";
        dp[p][q][r] = ans;
        return ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        int ans = dfs(0,0,0,grid);
        return max(0,ans);
    }
};