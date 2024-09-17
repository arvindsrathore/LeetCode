// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<pair<int,int>> a;
        for(int i=0;i<tasks.size();i++){
            a.push_back({tasks[i][1]-tasks[i][0],i});
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        int ans = 0,tot = 0;;
        for(int i=0;i<a.size();i++){
            int j = a[i].second;
            int consume = tasks[j][0];
            int need = tasks[j][1];
            if(ans<need){
                tot+=(need-ans);
                ans = need;
            }
            ans-=consume;
        }
        return tot;
    }
};