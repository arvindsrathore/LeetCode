//https://leetcode.com/problems/min-stack

class MinStack {
public:
    vector<int> v;
    multiset<int> s;
    MinStack() {
        v.clear();
    }
    
    void push(int val) {
        v.push_back(val);
        s.insert(val);
    }
    
    void pop() {
        int del = (*v.rbegin());
        v.pop_back();
        if(s.find(del)!=s.end())    s.erase(s.find(del));
    }
    
    int top() {
        return (*v.rbegin());
    }
    
    int getMin() {
        return (*s.begin());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
 
 // ----------------------------------------------------------------------------------------------------
 class MinStack {
public:
    vector<int> v,s;
    MinStack() {
        v.clear();
        s.clear();
    }
    
    void push(int val) {
        v.push_back(val);
        if(s.size())    s.push_back(min(val,(*s.rbegin())));
        else            s.push_back(val);
    }
    
    void pop() {
        v.pop_back();
        s.pop_back();
    }
    
    int top() {
        return (*v.rbegin());
    }
    
    int getMin() {
        return (*s.rbegin());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */