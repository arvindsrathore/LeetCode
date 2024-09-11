// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool pal(string s,int l,int r){
        for(int i=l;i<=r;i++){
            if(s[i]!=s[r+l-i])    return false;
        }
        return true;
    }
    vector<vector<string>> best;
    vector<string> ans;
    void f(string s,int prev,int idx){
        // cout<<prev<<" "<<idx<<"\n";
        if(prev==s.size()){
            best.push_back(ans);return;
        }
        if(pal(s,prev,idx)){
            string curr="";for(int i=prev;i<=idx;i++)    curr+=s[i];
            ans.push_back(curr);
            f(s,idx+1,idx+1);
            ans.pop_back();
        }
        if(idx==s.size()){
            return;
        }
        f(s,prev,idx+1);
    }
    vector<vector<string>> partition(string s) {
        f(s,0,0);
        return best;
    }
};