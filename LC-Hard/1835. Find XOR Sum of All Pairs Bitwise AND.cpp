// https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/description/

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        int g1=0;
        for(int i=0;i<n;i++){
            g1=g1^arr1[i];
        }
        int g2=0;
        for(int i=0;i<m;i++){
            g2=g2^arr2[i];
        }
        int ans = g1&g2;
        return ans;
    }
};