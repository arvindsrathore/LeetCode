// https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        int ans=0;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i==-1 && j==-1){
                if(!q.empty())  q.push({-1,-1});
                ans++;continue;
            }
            int dx[4] = {-1,0,1,0};
            int dy[4] = {0,-1,0,1};
            for(int d=0;d<4;d++){
                int x=i+dx[d];
                int y=j+dy[d];
                if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1){
                    grid[x][y] = 2;
                    q.push({x,y});
                }
            }
        }
        for(int i=0;i<n;i++)    for(int j=0;j<m;j++)    if(grid[i][j]==1)   return -1;
        return ans-1;
    }
};