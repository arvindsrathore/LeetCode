// 2024-09-14 15:43:37
// https://codeforces.com/problemset/problem/1968/F
#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
using namespace std;

void basic(){
	int n,q;cin>>n>>q;
	vector<int> a(n);
	for(auto &x:a){
		cin>>x;
	}
	map<int,vector<int>> mp;
	vector<int> prexor(n+1,0);
	prexor[0]=0;
	mp[0].push_back(0);
	for(int i=0;i<n;i++){
		prexor[i+1] = prexor[i]^a[i];
		mp[prexor[i+1]].push_back(i+1);
	}
	while(q--){
		int L,R;cin>>L>>R;
		int current = prexor[R] ^ prexor[L-1];
		int d = R-L+1;
		if(current==0 && d>=2){
			cout<<"YES"<<"\n";continue;
		}
		int l = *--lower_bound(all(mp[prexor[L-1]]),R);
		int r = *lower_bound(all(mp[prexor[R]]),L);
		if(l>r){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	cout<<"\n";
}

signed main(){
	int t = 1;
	cin>>t;
	while(t--){
		basic();
	}
}
