//https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/

class Solution {
public:
    struct dsu {
        vector<vector<int>> lst;
        vector<int> parent;
        
        dsu(int N) {
            lst.resize(N+5);
            parent.resize(N+5);
            for (int i = 0; i < N; ++i) {
                make_set(i);
            }
        }

        void make_set(int v) {
            lst[v] = vector<int>(1, v);
            parent[v] = v;
        }

        int find_set(int v) {
            if (v == parent[v]) {
                return v;
            }
            return parent[v] = find_set(parent[v]);
        }

        void union_sets(int a, int b) {
            a = find_set(a);
            b = find_set(b);
            if (a != b) {
                if (lst[a].size() < lst[b].size()) {
                    swap(a, b);
                }
                while (!lst[b].empty()) {
                    int v = lst[b].back();
                    lst[b].pop_back();
                    parent[v] = a;
                    lst[a].push_back(v);
                }
            }
        }
    };

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
       vector<int> adj[n];
       dsu ds(n);
       
       for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        ds.union_sets(u,v);
       }
       vector<int> ans(n,-1);
       for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];

        int pr=ds.find_set(u);
        if(ans[pr]==-1) ans[pr] = w;
        else    ans[pr] = (ans[pr]&w);
       }
       vector<int> realans;
       for(int i=0;i<query.size();i++){
        int u=query[i][0];
        int v=query[i][1];
        if(ds.find_set(u) == ds.find_set(v)) realans.push_back(ans[ds.find_set(u)]);
        else    realans.push_back(-1);   
       }
       return realans;
    }
};