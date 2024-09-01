//https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/

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

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        dsu one(n),two(n);
        int ans=0;
        for(int i=0;i<m;i++){
            int typ=edges[i][0];
            int u=edges[i][1];
            int v=edges[i][2];
            if(typ!=3)  continue;
            int f=0;
            if(one.find_set(u)!=one.find_set(v)){
                f++;
                one.union_sets(u,v);
                two.union_sets(u,v);
            }
            if(two.find_set(u)!=two.find_set(v)){
                f++;
                one.union_sets(u,v);
                two.union_sets(u,v);
            }
            if(f==0)   ans++;
        }
        for(int i=0;i<m;i++){
            int typ=edges[i][0];
            int u=edges[i][1];
            int v=edges[i][2];
            if(typ==3)  continue;
            if(typ==1){
                if(one.find_set(u)!=one.find_set(v)){
                    one.union_sets(u,v);
                }
                else{
                    ans++;
                }
            }
            else{
                if(two.find_set(u)!=two.find_set(v)){
                    two.union_sets(u,v);
                }
                else{
                    ans++;
                }
            }
        }
        if(one.lst[one.find_set(1)].size()!=n || two.lst[two.find_set(1)].size()!=n)    return -1;
        return ans;
    }
};
