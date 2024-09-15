// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/description/

class Solution {
public:
    int solve(string s,int l,int r){
        if(l==r || l>r) return 0;
        vector<int> a(26,-1),b(26,-1);
        for(int i=l;i<=r;i++){
            if(a[s[i]-'a']==-1) a[s[i]-'a'] = i;
            b[s[i]-'a'] = i;
        }
        int ans = 1e8;
        int mn = -1;
        for(int i=0;i<26;i++){
            if(a[i]!=-1 && a[i]!=b[i] &&  (a[i]-l+r-b[i])<ans){
                ans = a[i]-l+r-b[i];
                mn = i;
            }
        }
        for(int i=a[mn];i>=l+1;i--){
            swap(s[i],s[i-1]);
        }
        for(int i=b[mn]+1;i<=r;i++){
            swap(s[i],s[i-1]);
        }
        return ans + solve(s,l+1,r-1);
    }
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        return solve(s,0,n-1);
    }
};

// -----------------------------------------------------------------------------

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0;
        while(s.size()){
            int i=s.find(s.back());
            if(i==s.size()-1){
                ans+=i/2;
            }
            else{
                ans+=i;
                s.erase(i,1);
            }
            s.pop_back();
        }
        return ans;
    }
};