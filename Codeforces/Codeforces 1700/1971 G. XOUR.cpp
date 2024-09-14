// 2024-09-14 13:57:31

#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
using namespace std;

void basic(){
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	map<int,multiset<int>> q;
	for(int i=0;i<n;i++){
		q[a[i]>>2].insert(a[i]);
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		int pr = a[i]>>2;
		ans.push_back(*q[pr].begin());
		q[pr].erase(q[pr].begin());
	}
	for(auto x:ans){
		cout<<x<<" ";
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
