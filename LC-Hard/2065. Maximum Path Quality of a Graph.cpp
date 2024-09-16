// https://leetcode.com/problems/maximum-path-quality-of-a-graph/description/

class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> best;
    void dfs(int rt,int time,int ans,int k,vector<int>& values,vector<int>& vis){
        int f=0;
        if(vis[rt]==0) f=1;
        int has = vis[rt]==0 ? values[rt] : 0;
        vis[rt] = 1;
        
        for(auto v:adj[rt]){
            int ch = v.first;
            int t = v.second;
            if(time+t<=k){
                dfs(ch,time+t,ans+has,k,values,vis);
            }
        }
        if(f)vis[rt] = 0;
        best[rt] = max(best[rt],ans+has);
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        adj = vector<vector<pair<int,int>>> (n);
        best = vector<int>(n,0);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int t=e[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        vector<int> vis(n,0);
        dfs(0,0,0,maxTime,values,vis);
        return best[0];
    }
};