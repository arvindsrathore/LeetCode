// https://leetcode.com/problems/sequentially-ordinal-rank-tracker/description/

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<pair<int, string>, null_type, less<pair<int, string>>, rb_tree_tag,
             tree_order_statistics_node_update> ost;
class SORTracker {
public:
    ost st;
    int i = 0;
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        st.insert({-score,name});
    }
    
    string get() {
        auto it = (*st.find_by_order(i++));
        return it.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */