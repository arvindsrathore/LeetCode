// https://leetcode.com/problems/stone-game-iii/description/

// Idiotic TLE 
// METHOD 1
class Solution {
public:
    int dp[50005][2];
    int f(int idx,int chance,vector<int>& stones){
        int n=stones.size();
        if(idx>=n)  return 0;
        if(dp[idx][chance]!=-1) return dp[idx][chance];
        if(chance==0){
            int ans = -1e9;
            ans = stones[idx] + f(idx+1,1,stones);
            if(idx+1<n) ans = max(ans,stones[idx] + stones[idx+1] + f(idx+2,1,stones));
            if(idx+2<n) ans = max(ans,stones[idx] + stones[idx+1] + stones[idx+2] + f(idx+3,1,stones));
            return dp[idx][chance] = ans;
        }
        else{
            int ans = 1e9;
            ans = min(ans,f(idx+1,0,stones)),
            ans = min(ans,f(idx+2,0,stones));
            ans = min(ans,f(idx+3,0,stones));
            return dp[idx][chance] = ans;
        }
        return 0;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        memset(dp,-1,sizeof(dp));
        int ans = f(0,0,stoneValue);
        int sm = 0;for(auto x:stoneValue)   sm+=x;
        int ans2 = sm-ans;
        if(ans==ans2)   return "Tie";
        if(ans>ans2)    return "Alice";
        return "Bob";
    }
};

// -----------------------------------------------------------------------
// METHOD 2
class Solution {
public:
    vector<int> dp;
    int f(int idx,vector<int>& stones){
        int n=stones.size();
        if(idx>=n)  return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        int ans = -1e9;
        ans = stones[idx] - f(idx+1,stones);
        if(idx+1<n) ans = max(ans,stones[idx] + stones[idx+1] - f(idx+2,stones));
        if(idx+2<n) ans = max(ans,stones[idx] + stones[idx+1] + stones[idx+2] - f(idx+3,stones));
        return dp[idx] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        dp = vector<int> (50001,-1);
        int ahead = f(0,stoneValue);
        int sm = 0;for(auto x:stoneValue)   sm+=x;
        int ans = (sm+ahead)/2;
        int ans2 = sm-ans;
        if(ans==ans2)   return "Tie";
        if(ans>ans2)    return "Alice";
        return "Bob";
    }
};

// -----------------------------------------------------------------------
// METHOD 3
class Solution {
public:
    vector<int> dp;
    int f(int idx,vector<int>& stones){
        int n=stones.size();
        if(idx>=n)  return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        int ans = -1e9;
        int tot = 0;
        for(int i=0;i<3 and idx+i < n;i++){
            tot += stones[idx+i];
            ans = max(ans, tot - f(idx+i+1, stones));
        }
        return dp[idx] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        dp = vector<int> (50001,-1);
        int ahead = f(0,stoneValue);
        int sm = 0;for(auto x:stoneValue)   sm+=x;
        int ans = (sm+ahead)/2;
        int ans2 = sm-ans;
        if(ans==ans2)   return "Tie";
        if(ans>ans2)    return "Alice";
        return "Bob";
    }
};