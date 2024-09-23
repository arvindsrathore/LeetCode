// https://leetcode.com/problems/maximum-xor-score-subarray-queries/description/

class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& a, vector<vector<int>>& queries) {
        int n=a.size();
        vector<vector<int>> t(n,vector<int>(n,0));
        for(int i=0;i<n;i++)    t[i][i]=a[i];
        for(int i=2;i<=n;i++){
            for(int j=0;j+i-1<n;j++){
                int k=j+i-1;
                t[j][k] = t[j][k-1]^t[j+1][k];
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j+i-1<n;j++){
                int k=j+i-1;
                t[j][k] = max({t[j][k],t[j][k-1],t[j+1][k]});
            }
        }
        vector<int> ans;
        for(auto x:queries){
            ans.push_back(t[x[0]][x[1]]);
        }
        return ans;
    }
};