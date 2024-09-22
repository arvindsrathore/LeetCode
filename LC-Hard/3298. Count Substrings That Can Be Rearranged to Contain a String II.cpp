class Solution {
public:
    bool f(vector<int>& a,vector<int>& b){
        for(int i=0;i<26;i++){
            if(a[i]>b[i])  return 0;
        }
        return 1;
    }
    long long validSubstringCount(string s, string t) {
        int n = s.size();
        vector<int> p(26,0);
        for(char x:t)   p[x-'a']++;
        int l=0,r=0;
        vector<int> q(26,0);
        long long ans = 0;
        while(l<n){
            if(f(p,q)){
                ans+=(n-r+1);
                q[s[l]-'a']--;
                l++;
            }
            else if(r<n){
                q[s[r]-'a']++;
                r++;
            }
            else{
                q[s[l]-'a']--;
                l++;
            }
        }
        return ans;
    }
};