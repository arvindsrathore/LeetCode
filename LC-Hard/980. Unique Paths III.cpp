// https://leetcode.com/problems/unique-paths-iii/description/

class Solution {
public:
    int ans = 0;
    int em = 0;
    void solve(int idx,int jdx,vector<vector<int>>&grid,vector<vector<int>>vis,int cnt){
        int n=grid.size();
        int m=grid[0].size();
        if(idx<0 || idx>=n || jdx<0 || jdx>=m)    return;
        if(vis[idx][jdx])   return;
        vis[idx][jdx] = 1;
        if(grid[idx][jdx]==-1)  return;
        if(grid[idx][jdx]==2){
            cnt++;
            if(cnt==em)ans++;
            return;
        }
        solve(idx+1,jdx,grid,vis,cnt+1);
        solve(idx,jdx+1,grid,vis,cnt+1);
        solve(idx-1,jdx,grid,vis,cnt+1);
        solve(idx,jdx-1,grid,vis,cnt+1);
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=-1){
                    em++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    solve(i,j,grid,vis,0);
                }
            }
        }
        return ans;
    }
};