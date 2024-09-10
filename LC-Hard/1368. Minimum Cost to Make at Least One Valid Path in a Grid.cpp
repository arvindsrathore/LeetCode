// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(!(i>=0 && j>=0 && i<n && j<m))   continue;
            if(vis[i][j])   continue;
            vis[i][j] = 1;

            if(i==n-1 && j==m-1)    return dist;
            int left=1,right=1,up=1,down=1;
            if(grid[i][j]==1)   right=0;
            if(grid[i][j]==2)   left=0;
            if(grid[i][j]==3)   down=0;
            if(grid[i][j]==4)   up=0;
            pq.push({dist+left,{i,j-1}});
            pq.push({dist+right,{i,j+1}});
            pq.push({dist+down,{i+1,j}});
            pq.push({dist+up,{i-1,j}});
        }
        return 1e9;
    }
};