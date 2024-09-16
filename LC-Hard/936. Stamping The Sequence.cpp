// https://leetcode.com/problems/stamping-the-sequence/description/

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        int m = stamp.size();
        vector<int> ans;
        vector<int> a(n,0);
        int i=0,t=0;
        while(t<10*n){
            int cnt=0;
            for(int j=i;j<i+m;j++){
                if(target[j] == stamp[j-i] || target[j]=='?'){
                    cnt++;
                }
                else{
                    break;
                }
            }
            t++;
            if(cnt==m){
                for(int j=i;j<i+m;j++)  target[j]='?';
                ans.push_back(i);
            }
            i = (i+1)%n;
            if(count(target.begin(),target.end(),'?')==n)   break;
        }
        if(t>=10*n) ans.clear();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};