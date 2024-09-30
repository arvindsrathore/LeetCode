// https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/description/

class Solution {
public:
    long long numberOfSubarrays(vector<int>& a) {
        stack<pair<int,int>> st;
        int n = a.size();
        long long ans = n;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({a[i],1});
            }
            else{
                while(st.size() && st.top().first<a[i]){
                    st.pop();
                }
                if(st.empty()){
                    st.push({a[i],1});
                }
                else if(st.top().first==a[i]){
                    int val = st.top().second;
                    ans+=val;
                    st.pop();st.push({a[i],val+1});
                }
                else{
                    st.push({a[i],1});
                }
            }
        }
        return ans;
    }
};