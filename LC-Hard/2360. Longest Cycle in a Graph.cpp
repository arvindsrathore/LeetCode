//https://leetcode.com/problems/longest-cycle-in-a-graph/

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis,tin;
    int ans=-1;
    void dfs(int rt,int time){
        vis[rt] = 2;
        tin[rt] = time;time++;
        for(auto ch:adj[rt]){
            if(vis[ch]==1)  continue;
            if(vis[ch]==2){
                ans = max(ans,time-tin[ch]);
            }
            else{
                dfs(ch,time);
            }
        }
        vis[rt] = 1;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        adj = vector<vector<int>> (n);
        vis = vector<int> (n,0);
        tin = vector<int> (n,0);
        
        for(int i=0;i<n;i++){
            int v=edges[i];
            if(v==-1)   continue;
            adj[i].push_back(v);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,0);
            }
        }
        return ans;
    }
};