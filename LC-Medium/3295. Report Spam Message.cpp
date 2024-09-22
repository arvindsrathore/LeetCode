class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string,int> mp;
        for(auto x:bannedWords) mp[x]=1;
        int cnt=0;
        for(auto x:message){
            cnt+=(mp[x]);
        }
        return cnt>=2;
    }
};