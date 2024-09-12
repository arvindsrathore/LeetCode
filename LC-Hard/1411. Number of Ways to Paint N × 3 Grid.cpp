// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/

class Solution {
public:
    int numOfWays(int n) {
        long long a121 = 6;
        long long a123 = 6;
        int mod = 1e9+7;
        for(int i=1;i<n;i++){
            long long b121 = a121*3+a123*2;
            long long b123 = a121*2+a123*2;
            a121 = b121 % mod;
            a123 = b123 % mod;
        }
        return (a121+a123)%mod;
    }
};