// https://leetcode.com/problems/ipo/description/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> a;
        int n=profits.size();
        for(int i=0;i<n;i++){
            a.push_back({capital[i],profits[i]});
        }
        sort(a.begin(),a.end());
        priority_queue<int> pq;
        
        int i = 0;
        for(int j=0;j<k;j++){
            while(i<n && a[i].first<=w){
                pq.push(a[i].second);i++;
            }
            if(pq.size()){
                w+=pq.top();pq.pop();
            }
            else    break;
        }
        return w;
    }
};