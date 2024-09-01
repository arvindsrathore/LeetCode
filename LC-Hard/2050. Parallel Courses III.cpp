//https://leetcode.com/problems/parallel-courses-iii/description/

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int m=relations.size();
        vector<int> indegree(n+1,0);
        vector<int> wait(n,0);
        vector<int> adj[n+1];
        for(int i=0;i<m;i++){
            int u=relations[i][0];
            int v=relations[i][1];
            indegree[v]++;
            adj[u].push_back(v);
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int ans=0;
        while(!q.empty()){
            int rt = q.front();q.pop();
            wait[rt-1] += time[rt-1];
            for(auto ch:adj[rt]){
                wait[ch-1] = max(wait[ch-1],wait[rt-1]);
                indegree[ch]--;
                if(indegree[ch]==0) q.push(ch);
            }
            ans = max(ans,wait[rt-1]);
        }
        return ans;
    }
};