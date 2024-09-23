class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        int n=a.size();
        int l=k,r=k,m=a[k];
        int ans = m;
        while(l>0 || r<n-1){
            if(l==0 || r<n-1 && a[r+1]>a[l-1]){
                r++;
            }
            else{
                l--;
            }
            m = min(m,min({a[r],a[l]}));
            ans = max(ans,m*(r-l+1));
        }
        return ans;
    }
};