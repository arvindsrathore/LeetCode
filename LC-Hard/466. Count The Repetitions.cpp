class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unordered_map<int,int> r,nx;
        int j=0,cnt=0;
        for(int k=1;k<=n1;k++){
            for(int i=0;i<s1.size();i++){
                if(s1[i]==s2[j]){
                    j++;
                    if(j==s2.size()){
                        j=0;
                        cnt++;
                    }
                }
            }
            r[k] = cnt;
            nx[k] = j;
            for(int st=0;st<k;st++){
                if(nx[st] == j){
                    int p = r[st];
                    int q = (n1-st)/(k-st)*(r[k]-p);
                    int s = r[st+(n1-st)%(k-st)] - p;
                    return (p+q+s)/n2;
                }
            }
        }
        return r[n1]/n2;
    }
};