// https://leetcode.com/problems/sum-of-scores-of-built-strings/description/

class Solution {
public:
    vector<int> z_function(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    long long sumScores(string s) {
        vector<int> ans = z_function(s);
        long long best = s.size();
        for(auto x:ans) best+=x;
        return best;
    }
};