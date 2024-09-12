// https://leetcode.com/problems/number-of-atoms/description/

// Diabolical Implementation
class Solution {
public:
    void solve(int l,int r,string &s,vector<int>& vis,map<string,int>& count,map<int,map<string,int>>& ans){
        string t="";
        string val="";
        if(l>-1)vis[l] = 1;
        if(r<s.size())vis[r] = 1;
        for(int i=l+1;i<r;i++){
            if(vis[i])  continue;
            vis[i] = 1;
            if(s[i]>='A' && s[i]<='Z'){
                if(val.size()){
                    count[t] += stoi(val);
                    val = "";
                    t = "";
                }
                if(t.size()){
                    count[t] += 1;
                    t="";
                }
                t+=s[i];
            }
            else if(s[i]>='a' && s[i]<='z'){
                t+=s[i];
            }
            else if(s[i]>='0' && s[i]<='9'){
                val+=s[i];
            }
        }
        if(val.size()>0){
            count[t] += stoi(val);
            t="";
            val="";
        }
        if(t.size()>0){
            count[t] += 1;
            t="";
        }
        int add = 0;
        for(int i=r+1;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9')  add = (add*10+(s[i]-'0'));
            else    break;
            vis[i] = 1;
        }
        for(int i=l+1;i<r;i++){
            for(auto x:ans[i]){
                count[x.first]+=x.second;
            }
            ans[i].clear();
        }
        for(auto &x:count){
            if(add)x.second*=add;
        }
        ans[l] = count;
    }
    string countOfAtoms(string formula) {
        vector<pair<int,int>> v;
        stack<int> s;
        int n=formula.size();
        for(int i=0;i<n;i++){
            if(formula[i]=='('){
                s.push(i);
            }
            if(formula[i]==')'){
                v.push_back({s.top(),i});
                s.pop();
            }
        }
        v.push_back({-1,n});

        map<int,map<string,int>> ans;

        vector<int> vis(n,0);

        for(auto x:v){
            int l=x.first;
            int r=x.second;
            map<string,int> count;
            solve(l,r,formula,vis,count,ans);
        }
        string finalAns = "";
        for(auto x:ans[-1]){
            // cout<<x.first<<" "<<x.second<<"\n";
            finalAns+=x.first;
            if(x.second>1){
                finalAns+=to_string(x.second);
            }
        }
        return finalAns;
    }
};