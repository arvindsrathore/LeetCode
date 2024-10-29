// https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/description/

// 100th Hard Questions

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int cnt=0,ans=0;
        map<int,int> mp;
        for(int x:rolls){
            mp[x]++;
            if(mp[x]==1)    cnt++;
            //All visited once like 1234...1234...1234
            if(cnt==k){
                cnt=0;mp.clear();ans++;
            }
        }
        return ans+1;
    }
};