// https://leetcode.com/problems/stone-game-ii/description/

class Solution {
public:
    vector<vector<int>> dp;
    int f(int idx,int M,vector<int>& piles,vector<int>& suf){
        int n=piles.size();
        if(idx>=n){
            return 0;
        }
        if(dp[idx][M]!=-1)  return dp[idx][M];
        int ans=0;
        for(int i=1;i<=2*M;i++){
            int p = suf[idx] - f(idx+i,max(M,i),piles,suf);
            ans = max(ans,p);
        }
        return dp[idx][M] = ans;
        
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        dp = vector<vector<int>>(n+1,vector<int>(4*n,-1));
        vector<int> suf(n+1);
        suf[n-1] = piles[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i] = piles[i] + suf[i+1];
        }
        int ans = f(0,1,piles,suf);
        return ans;
    }
};

// ------------------------------------------------------------------------------

class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(int idx,int M,int chance,vector<int>& piles,vector<int>& pre){
        int n=piles.size();
        if(idx>=n){
            return 0;
        }
        if(dp[idx][M][chance]!=-1)  return dp[idx][M][chance];
        if(chance==0){
            int ans=0;
            for(int i=1;i<=2*M;i++){
                int p = pre[min(n,idx+i)] - pre[idx] + f(idx+i,max(M,i),1,piles,pre);
                ans = max(ans,p);
            }
            return dp[idx][M][chance] = ans;
        }
        else{
            int ans=1e9;
            for(int i=1;i<=2*M;i++){
                int p = f(idx+i,max(M,i),0,piles,pre);
                ans = min(ans,p);
            }
            return dp[idx][M][chance] = ans;
        }
        return 0;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        dp = vector<vector<vector<int>>>(n+1,vector<vector<int>>(4*n,vector<int>(2,-1)));
        vector<int> pre;
        int x=0;
        pre.push_back(x);
        for(auto y:piles){
            x+=y;
            pre.push_back(x);
        }
        int ans = f(0,1,0,piles,pre);
        return ans;
    }
};