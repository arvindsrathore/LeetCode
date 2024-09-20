// https://leetcode.com/problems/maximum-score-of-spliced-array/description/

class Solution {
public:
    int f(vector<int>& a, vector<int>& b){
        int sm = 0,ans = 0;
        for(int i=0;i<a.size();i++){
            sm = max(b[i]-a[i],sm+b[i]-a[i]);
            ans = max(ans,sm);
        }
        return ans;
    }
    int maximumsSplicedArray(vector<int>& a, vector<int>& b) {
        return 
            max(accumulate(a.begin(),a.end(),0) + f(a,b),
                accumulate(b.begin(),b.end(),0) + f(b,a));
    }
};