// https://leetcode.com/problems/maximum-performance-of-a-team/description/

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<long,long>> a;
        for(int i=0;i<n;i++){
            a.push_back({efficiency[i],speed[i]});
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        long ans = 0;
        long best = 0;
        long mod = 1e9+7;
        for(int i=0;i<n;i++){
            pq.push(a[i].second);
            ans+=a[i].second;
            if(pq.size()>k){
                ans-=pq.top();pq.pop();
            }
            best = max(best,(ans*a[i].first));
        }
        return best%mod;
    }
};