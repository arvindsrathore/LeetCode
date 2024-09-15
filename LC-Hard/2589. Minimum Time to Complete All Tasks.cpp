// https://leetcode.com/problems/minimum-time-to-complete-all-tasks/description/

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){
            return (a[1]!=b[1]) ? a[1]<b[1] : a[0]<b[0];
        });
        unordered_map<int,int> vis;
        int ans = 0;
        for(auto& task:tasks){
            int dur = task[2];
            for(int j=task[0];j<=task[1];j++)   if(vis[j]) dur--;
            for(int j=task[1];dur>0;j--){
                cout<<j;
                if(!vis[j]){
                    dur--;
                    vis[j]=1;
                    ans++;
                }
            }
        }
        return ans;
    }
};