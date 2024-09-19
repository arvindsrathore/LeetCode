// https://leetcode.com/problems/split-message-based-on-limit/description/

class Solution {
public:
    bool ispossible(string s,int mid,int limit,vector<string>& ans){
        string curr = "";
        int val = 1;
        int n = s.size();
        int cnt = 0;
        string right = "/"+to_string(mid)+">"; 
        string now = "<"+to_string(val)+right;
        for(int i=0;i<n;i++){
            if((cnt+now.size()) == limit){
                ans.push_back(curr+now);
                val++;
                cnt = 0;
                now = "<"+to_string(val)+right;
                curr="";
            }
            cnt++;
            curr+=s[i];
        }
        if((cnt+now.size())>0 && (cnt+now.size()<=limit))ans.push_back(curr+now);
        else if((cnt+now.size())>limit){
            // cout<<mid<<" "<<cnt+now.size()<<"\n";
            curr={};return 1;
        }
        // for(auto x:ans) cout<<x<<"\n";
        // cout<<"\n";
        return ((int)ans.size()<=mid);
    }
    vector<string> solve(int l,int r,string message, int limit){
        vector<string> ans;
        while(l<=r){
            int mid = (l+(r-l)/2);
            vector<string> curr;
            // cout<<l<<" "<<r<<" "<<mid<<"\n";
            if(ispossible(message,mid,limit,curr)){
                if(curr.size()==mid)ans = curr;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    vector<string> splitMessage(string message, int limit) {
        if (limit < 6) return {};
        int l=1,r=10;
        vector<string> ans;
        while(r<=1e4){
            vector<string> now = solve(l,r-1,message,limit);
            // cout<<l<<" "<<r-1<<"\n";
            // for(auto x:now) cout<<x<<" ";
            // cout<<"\n";
            if(ans.size()==0){
                ans = now;
            }
            else if(now.size()>0 && ans.size()>now.size()){
                ans = now;
            }
            l*=10;
            r*=10;
        }
        return ans;
    }
};