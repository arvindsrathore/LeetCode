// https://leetcode.com/problems/max-points-on-a-line/

//O(n^3)
class Solution {
public:
    long long d(vector<int> &a,vector<int> &b){
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1)    return 1;
        map<pair<int,int>,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==k)    continue;
                    long long d1 = (d(points[i],points[j]));
                    long long d2 = (d(points[j],points[k]));
                    long long d3 = (d(points[i],points[k]));
                    long long p = 4*d1*d2;
                    long long q = (d3-(d1+d2))*(d3-(d1+d2));
                    if(p==q){
                        mp[{i,k}]++;
                    }
                }
            }
        }
        int ans = 0;
        for(auto x:mp){
            ans = max(ans,x.second);
        }
        return ans;
    }
};
// --------------------------------------------------------------------
// O(n^2)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        
        int ans = 2;
        for (int i = 0; i < n - 1; ++i) {
            map<pair<int, int>, int> slopeCount;
            int duplicate = 0;
            int currentMax = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                if (dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }

                int gcd = __gcd(dx, dy);
                dx /= gcd;
                dy /= gcd;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                slopeCount[{dx, dy}]++;
                currentMax = max(currentMax, slopeCount[{dx, dy}]);
            }

            ans = max(ans, currentMax + duplicate + 1);
        }

        return ans;
    }
};
