// https://leetcode.com/problems/similar-string-groups/description/

class Solution {
public:
    int diff(string a,string b){
        int cnt=0;
        for(int i=0;i<a.size();i++){
            cnt+=(a[i]!=b[i]);
        }
        return cnt;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        queue<string> q;
        vector<int> vis(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i] = 1;
                q.push(strs[i]);
                ans++;
                while(!q.empty()){
                    string tp = q.front();q.pop();
                    for(int j=i+1;j<n;j++){
                        if(diff(tp,strs[j])<=2 && !vis[j]){
                            vis[j] = 1;
                            q.push(strs[j]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};