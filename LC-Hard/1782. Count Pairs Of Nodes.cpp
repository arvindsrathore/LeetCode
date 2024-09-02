//https://leetcode.com/problems/count-pairs-of-nodes/description/

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        map<pair<int,int>,int> dup;
        vector<int> count(n+1,0);
        int m=edges.size();
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            count[u]++;
            count[v]++;
            dup[{max(u,v),min(u,v)}]++;
        }
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(count[i]);
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        
        for(int j=0;j<queries.size();j++){
            int k=queries[j];
            int cnt=0;
            for(int i=0;i<v.size();i++){
                int current = v[i];
                int req=max(k-current,0);
                int l=i+1,r=v.size()-1;
                int idx=-1;
                while(l<=r){
                    int mid = (l+r)/2;
                    if(v[mid]>req){
                        idx=mid;
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
                int count=0;
                if(idx!=-1) count=v.size()-idx;
                cnt+=count;
            }
            for(auto x:dup){
                int u=x.first.first;
                int v=x.first.second;
                int w=x.second;
                if(count[u]+count[v]>queries[j] && count[u]+count[v]-w <= queries[j]){
                    cnt--;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};