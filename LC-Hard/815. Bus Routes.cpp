// https://leetcode.com/problems/bus-routes/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(auto y:routes[i]){
                adj[y].push_back(i);
            }
        }
        queue<int> q;
        q.push(source);
        q.push(-1);
        map<int,int> vis;
        int ans = 0;
        while(!q.empty()){
            int rt = q.front();q.pop();
            if(rt==-1){
                if(!q.empty())  q.push(-1);
                ans++;
                continue;
            }
            if(rt==target)  return ans;
            for(auto x:adj[rt]){
                if(!vis[x]){
                    vis[x] = 1;
                    for(auto ch:routes[x]){
                        q.push(ch);
                    }
                }
            }
        }
        return -1;
    }
};