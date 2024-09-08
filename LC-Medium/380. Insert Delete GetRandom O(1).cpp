// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> mp;
    RandomizedSet() {
        v.clear();
        mp.clear();
    }
    
    bool insert(int val) {
        if(mp[val]>0){
            return false;
        }
        v.push_back(val);
        mp[val] = v.size();
        return true;
    }
    
    bool remove(int val) {
        if(mp[val]>0){
            v[mp[val]-1] = v[v.size()-1];
            mp[v[mp[val]-1]] = mp[val];
            mp[val]=0;            
            v.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int x=rand()%v.size();
        return v[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */