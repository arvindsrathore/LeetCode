// https://leetcode.com/problems/couples-holding-hands/description/

class Solution {
public:
    vector<int> lst[100];
    int parent[100];

    void make_set(int v) {
        lst[v] = vector<int>(1, v);
        parent[v] = v;
    }

    int find_set(int v) {
        return parent[v];
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (lst[a].size() < lst[b].size())
                swap(a, b);
            while (!lst[b].empty()) {
                int v = lst[b].back();
                lst[b].pop_back();
                parent[v] = a;
                lst[a].push_back (v);
            }
        }
    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        for(int i=0;i<n;i++){
            row[i]/=2;
            make_set(row[i]);
        }
        for(int i=0;i<n;i+=2){
            union_sets(row[i],row[i+1]);
        }
        int ans = 0;
        for(int i=0;i<=row.size()/2;i++){
            if(lst[i].size())ans+=(lst[i].size()-1);
        }
        return ans;
    }
};