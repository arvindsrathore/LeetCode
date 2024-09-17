// https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/description/

class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> side;
    vector<int> dp;
    int dfs(int rt,int pr=-1){
        int sm = 0;
        for(auto x:adj[rt]){
            int ch = x.first;
            int f = x.second;
            if(ch!=pr){
                sm+=(f+dfs(ch,rt));
            }
        }
        return side[rt] = sm;
    }
    void dfs2(int rt,int ans,int x,int pr=-1){
        dp[rt] = ans + side[rt];
        if(pr!=-1)  dp[rt] += (x+1)%2;
        for(auto x:adj[rt]){
            int ch = x.first;
            int f = x.second;
            if(ch!=pr){
                dfs2(ch,dp[rt]-side[ch]-f,f,rt);
            }
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adj = vector<vector<pair<int,int>>>(n);
        side = vector<int>(n,0);
        dp = vector<int>(n,0);
        for(int i=0;i<n-1;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        int ans = dfs(0);
        dfs2(0,0,0);
        return dp;
    }
};