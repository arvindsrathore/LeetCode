// https://leetcode.com/problems/robot-collisions/description/

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
        int n=positions.size();
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            a[i].first = positions[i];
            a[i].second = i;
        }
        sort(a.begin(),a.end());
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            int pos = a[i].first;
            int ind = a[i].second;
            int f = (directions[ind]=='R') ? 1:0;
            if(st.empty()){
                st.push({f,ind});
            }
            else{
                if(f){
                    st.push({f,ind});
                }
                else{
                    int chk=0;
                    while(st.size()){
                        if(st.top().first==0){
                            st.push({f,ind});
                            chk=1;
                            break;
                        }
                        int indt = st.top().second;
                        if(health[indt]==health[ind]){
                            chk=1;health[indt] = -1;health[ind] = -1;
                            st.pop();break;
                        }
                        else if(health[indt]>health[ind]){
                            chk=1;
                            health[ind] = -1;
                            health[indt]--;
                            break;
                        }
                        else{
                            health[indt] = -1;
                            health[ind]--;
                            st.pop();
                        }
                    }
                    if(chk==0)  st.push({f,ind});
                }
            }
        }
        vector<int> ans;
        for(auto x:health){
            if(x!=-1)   ans.push_back(x);
        }
        return ans;
    }
};