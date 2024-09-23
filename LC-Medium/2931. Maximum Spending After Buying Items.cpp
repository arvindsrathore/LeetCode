class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ans = 0;
        vector<long long> a;
        for(auto x:values){
            for(auto y:x){
                a.push_back(y);
            }
        }
        sort(a.begin(),a.end());
        for(long long i=0;i<a.size();i++){
            ans+=(i*a[i]+a[i]);
        }
        return ans;
    }
};