// https://leetcode.com/problems/all-oone-data-structure/description/

class AllOne {
public:
    priority_queue<pair<int,string>> mx;
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> mn;
    map<string,int> count;
    map<pair<string,int>,int> mp;
    AllOne() {
        
    }
    
    void inc(string key) {
        mp[{key,count[key]}] = 1;
        count[key]++;
        mp[{key,count[key]}] = 0;
        if(count[key]==0)   {count.erase(key);return;}
        mx.push({count[key],key});
        mn.push({count[key],key});
    }
    
    void dec(string key) {
        mp[{key,count[key]}] = 1;
        count[key]--;
        mp[{key,count[key]}] = 0;
        if(count[key]==0)   {count.erase(key);return;}
        mx.push({count[key],key});
        mn.push({count[key],key});        
    }
    
    string getMaxKey() {
        while(mx.size() && mp[{mx.top().second,mx.top().first}]==1){
            mx.pop();
        }
        if(mx.empty())  return "";
        return mx.top().second;
    }
    
    string getMinKey() {
        while(mn.size() && mp[{mn.top().second,mn.top().first}]==1){
            mn.pop();
        }
        if(mn.empty())  return "";
        return mn.top().second;
    }
};

// ---------------------------------------------------------

class AllOne {
public:
    map<string,int> count;
    map<int,set<string>> mp;
    set<int> val;
    AllOne() {
        
    }
    
    void inc(string key) {
        int prev = count[key];
        if(mp[prev].find(key)!=mp[prev].end()){
            mp[prev].erase(mp[prev].find(key));
        }
        auto it = val.find(count[key]);
        if(mp[prev].size()==0 && it!=val.end()) val.erase(it);
        count[key]++;
        val.insert(count[key]);
        mp[count[key]].insert(key);
    }
    
    void dec(string key) {
        int prev = count[key];
        if(mp[prev].find(key)!=mp[prev].end()){
            mp[prev].erase(mp[prev].find(key));
        }
        auto it = val.find(count[key]);
        if(mp[prev].size()==0 && it!=val.end()) val.erase(it);
        count[key]--;
        if(count[key]!=0)val.insert(count[key]);
        if(count[key]==0)   count.erase(key);
        else    mp[count[key]].insert(key);
    }
    
    string getMaxKey() {
        if(val.size()==0)    return "";
        int mx = *val.rbegin();
        return *mp[mx].begin();
    }
    
    string getMinKey() {
        if(val.size()==0)    return "";
        int mn = *val.begin();
        return *mp[mn].begin();
    }
};
