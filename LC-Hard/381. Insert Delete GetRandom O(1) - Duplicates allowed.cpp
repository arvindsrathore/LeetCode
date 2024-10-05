// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

class RandomizedCollection {
public:
    vector<pair<int,int>> a;
    unordered_map<int,vector<int>> mp;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        auto ans = mp.find(val) == mp.end();
        mp[val].push_back(a.size());
        a.push_back({val,mp[val].size()-1});
        return ans;
    }
    
    bool remove(int val) {
        auto ans = mp.find(val) != mp.end();
        if(ans){
            auto last = a.back();
            int lval = last.first;
            int lind = last.second;
            int val_last = mp[val].back();
            
            mp[lval][lind] = val_last;
            a[val_last] = last;
            mp[val].pop_back();
            if(mp[val].empty()) mp.erase(val);
            a.pop_back();
        }
        return ans;
    }
    
    int getRandom() {
        return a[rand()%a.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */