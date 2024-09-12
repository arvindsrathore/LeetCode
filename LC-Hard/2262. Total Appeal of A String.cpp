// https://leetcode.com/problems/total-appeal-of-a-string/description/

// miracle, miracle, 0 errors, single time accepted, not even compilation

class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        vector<int> t(n+1,0);
        set<char> st;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
            t[i+1] = t[i] + st.size();
        }
        vector<int> next(n,0);
        vector<int> prev(26,-1);
        for(int i=n-1;i>=0;i--){
            if(prev[s[i]-'a']==-1)  next[i] = n;
            else    next[i] = prev[s[i]-'a'];
            prev[s[i]-'a'] = i;
        }
        long long ans = 0;
        long long prv = 0;
        for(int i=0;i<n;i++){
            ans += (t[n] - prv);
            cout<<ans<<" "<<prv<<"\n";
            int nxt = next[i];
            prv += (nxt - i);
        }
        return ans;
    }
};