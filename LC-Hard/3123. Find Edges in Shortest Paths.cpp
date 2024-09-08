class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    int djks(){
        int n=adj.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(n,0);
        vector<int> dist(n,1e9);
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            int rt = pq.top().second;
            int wc = pq.top().first;pq.pop();
            vis[rt] = 1;
            for(auto x:adj[rt]){
                int ch=x.first;
                int w=x.second;
                if(wc+w<dist[ch]){
                    dist[ch]=wc+w;
                    pq.push({dist[ch],ch});
                }
            }
        }
        return dist[n-1];
    }
    map<pair<int,int>,bool> ans;
    bool dfs(int rt,int curr,vector<int> vis){
        if(rt==adj.size()-1){
            if(curr==0)return true;
            return false;
        }
        vis[rt] = 1;
        bool now = false;
        for(auto x:adj[rt]){
            int ch=x.first;
            int w=x.second;
            if(!vis[ch] && (curr-w)>=0){
                bool yes = dfs(ch,curr-w,vis);
                now = (yes or now);
                if(yes){
                    cout<<rt<<" "<<ch<<" "<<yes<<"\n";
                    ans[{ch,rt}] = true;
                    ans[{rt,ch}] = true;
                }
            }
        }
        return now;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        adj = vector<vector<pair<int,int>>>(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int shortestdist=djks();
        
        vector<int> vis(n,0);
        vector<bool> yes;
        dfs(0,shortestdist,vis);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(ans[{u,v}] or ans[{v,u}])    yes.push_back(true);
            else    yes.push_back(false);
        }

        return yes;
    }
};