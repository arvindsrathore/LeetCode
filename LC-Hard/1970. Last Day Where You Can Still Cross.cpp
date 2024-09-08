// https://leetcode.com/problems/last-day-where-you-can-still-cross/description/

class Solution {
public:
    bool dfs(int x,int y,vector<vector<int>> &vis){
        int row = vis.size();
        int col = vis[0].size();
        if(x>=0 && x<row && y>=0 && y<col){
            if(vis[x][y]==1)    return 0;
            vis[x][y] = 1;
            if(x==row-1)  return true;
            bool chk = dfs(x+1,y,vis) or
            dfs(x,y+1,vis) or
            dfs(x-1,y,vis) or
            dfs(x,y-1,vis);
            return chk;
        }
        return false;
    }
    bool check(int row, int col, vector<vector<int>>& cells,int mid){
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(int i=0;i<=mid;i++){
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;
            vis[x][y] = 1;
        }
        for(int i=0;i<col;i++){
            if(dfs(0,i,vis))  return true;
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=cells.size();
        int l=0,r=n-1;
        int ans=0;
        while(l<=r){
            int mid = l+(r-l)/2;
            bool f = check(row,col,cells,mid);
            cout<<"here"<<f<<"\n";
            if(f){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans+1;
    }
};