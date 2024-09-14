// 2024-09-14 12:40:03
// https://codeforces.com/problemset/problem/2004/D
#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
using namespace std;

void f(const std::vector<int>& s, int& ans, int u, int v) {
    if (s.empty()) return;

    int l = 0;
    int r = s.size() - 1;


    while (l <= r) {
        int mid = l + (r - l) / 2;
        int current_dist = std::abs(u - s[mid]) + std::abs(v - s[mid]);
        ans = std::min(ans, current_dist);

        if (mid > l) {
            int left_dist = std::abs(u - s[mid - 1]) + std::abs(v - s[mid - 1]);
            ans = std::min(ans, left_dist);
        }
        if (mid < r) {
            int right_dist = std::abs(u - s[mid + 1]) + std::abs(v - s[mid + 1]);
            ans = std::min(ans, right_dist);
        }

        if (mid > 0 && std::abs(u - s[mid - 1]) + std::abs(v - s[mid - 1]) < current_dist) {
            r = mid - 1;
        } else if (mid < s.size() - 1 && std::abs(u - s[mid + 1]) + std::abs(v - s[mid + 1]) < current_dist) {
            l = mid + 1;
        } else {
            break;
        }
    }
}

void basic(){
	int n,q;cin>>n>>q;
	vector<string> a(n);
	map<string,vector<int>> mp;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]].push_back(i);
		reverse(all(a[i]));
		mp[a[i]].push_back(i);
	}
	while(q--){
		int u,v;cin>>u>>v;u--;v--;
		string uc = a[u];
		string vc = a[v];
		if(uc[0]==vc[0] || uc[0]==vc[1] || uc[1]==vc[0] || uc[1]==vc[1]){
			cout<<abs(u-v)<<"\n";continue;
		}
		vector<int> want;
		string p = string(1, uc[0]) + vc[0];
		string q = string(1, uc[0]) + vc[1];
		string r = string(1, uc[1]) + vc[0];
		string s = string(1, uc[1]) + vc[1];
		int ans = 1e18;
		// cout<<p<<" "<<q<<" "<<r<<" "<<s<<"\n";
		f(mp[p],ans,u,v);
		f(mp[q],ans,u,v);
		f(mp[r],ans,u,v);
		f(mp[s],ans,u,v);
		if(ans==1e18)	ans=-1;
		cout<<ans<<"\n";
	}
}

signed main(){
	int t = 1;
	cin>>t;
	while(t--){
		basic();
	}
}
