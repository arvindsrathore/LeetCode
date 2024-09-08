// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int> nse(n,n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && a[i]<a[s.top()]){
                nse[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        vector<int> nse2(n,-1);
        while(!s.empty())   s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && a[i]<a[s.top()]){
                nse2[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int len = nse[i] - nse2[i]-1;
            // cout<<i<<" "<<nse[i]<<" "<<nse2[i]<<" "<<len<<"\n";
            ans = max(ans,len*a[i]);
        }
        // for(auto x:nse) cout<<x<<" ";
        return ans;
    }
};