// https://leetcode.com/problems/maximum-frequency-stack/description/

class FreqStack {
public:
    priority_queue<vector<int>> pq;
    map<int,int> mp;
    int t=0;
    FreqStack() {
        t=0;
        while(pq.size())    pq.pop();
        mp.clear();
    }
    
    void push(int val) {
        mp[val]++;
        t++;
        pq.push({mp[val],t,val});
    }
    
    int pop() {
        int tp=pq.top()[2];
        mp[tp]--;
        pq.pop();
        return tp;

    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */