//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    vector<vector<int>> vis;
    vector<vector<int>> dp;
    int best=1;
    int dfs(int i,int j,int prev,vector<vector<int>>& a){
        int n = a.size();
        int m = a[0].size();
        if(i<0 || i>=n || j<0 || j>=m) return -1e9;
        
        if(a[i][j]<=prev){
            return 0;
        }
        if(dp[i][j]!=-1)   return dp[i][j];
        int ans=1+max({   
                        dfs(i+1,j,a[i][j],a),
                        dfs(i,j+1,a[i][j],a),
                        dfs(i-1,j,a[i][j],a),
                        dfs(i,j-1,a[i][j],a)
                    });
        dp[i][j] = ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vis = vector<vector<int>>(n,vector<int>(m,0));
        dp = vector<vector<int>>(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    best = max(best,dfs(i,j,-1,a));
                    cout<<"\n";
                }
            }
        }
        return best;
    }
};