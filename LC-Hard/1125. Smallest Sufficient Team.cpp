// https://leetcode.com/problems/smallest-sufficient-team/description/

class Solution {
public:
    long long dp[64][1<<16+1];
    long long f(int idx,long long curr,long long want,vector<int>& p){
        if(curr==want)  return 0ll;
        if(idx>=p.size())  return (1ll<<idx)-1ll;
        if(dp[idx][curr]!=-1)   return dp[idx][curr];
        long long x = f(idx+1,curr,want,p);
        long long y = f(idx+1,curr|p[idx],want,p);
        y|=(1ll<<idx);
        bitset<64> a(x),b(y);
        if(a.count()<b.count()) return dp[idx][curr] = x;
        else    return dp[idx][curr] = y;
    }

    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) {
        memset(dp,-1,sizeof(dp));
        map<string,int> mp;
        long long want = 0;
        for(int i=0;i<req.size();i++)  mp[req[i]] = i,want+=(1<<i);
        vector<int> p;
        for(auto s:people){
            long long val = 0;
            for(int i=0;i<s.size();i++){
                val+=(1<<mp[s[i]]);
            }
            p.push_back(val);
        }
        long long ans = f(0,0,want,p);
        bitset<60> yes(ans);
        vector<int> best;
        for(int i=0;i<60;i++){
            if(yes[i])  best.push_back(i);
        }
        return best;
    }
};