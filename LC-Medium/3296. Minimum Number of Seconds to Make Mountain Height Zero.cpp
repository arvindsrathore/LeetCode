class Solution {
public:
    long long minNumberOfSeconds(int h, vector<int>& t) {
        int n = t.size();
        priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
            > pq;
        for(auto x:t){
            pq.push({x,x,2});
        }
        long long ans = 0;
        while(!pq.empty() && h>0){
            long long tp = pq.top()[0];
            long long fp = pq.top()[1];
            long long gp = pq.top()[2];
            pq.pop();h--;
            ans = max(ans,tp);
            pq.push({tp+fp*gp,fp,gp+1});
        }
        return ans;
    }
};