// https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder {
public:
    multiset<int> l,r;
    int sz = 0;
    MedianFinder() {
        l.clear();r.clear();
    }
    
    void addNum(int num) {
        sz++;
        if(l.size()==0 && r.size()==0){
            l.insert(num);return;
        }
        if(num<=*l.rbegin()){
            l.insert(num);
            while(l.size()>(sz+1)/2){
                r.insert(*l.rbegin());
                l.erase(--l.end());
            }
        }
        else{
            r.insert(num);
            while(r.size()>(sz/2)){
                l.insert(*r.begin());
                r.erase(r.begin());
            }
        }
    }
    
    double findMedian() {
        if((l.size()+r.size())%2==1){
            return *l.rbegin();
        }
        else{
            return (*l.rbegin()+*r.begin())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */