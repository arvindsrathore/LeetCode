// 2024-09-14 13:39:21
// https://codeforces.com/problemset/problem/1990/D
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
	for(auto &x:a){
		if(x%2==1)	x++;
	}
	int i=0;
	int ans = 0;
	for(;i<n;){
		if(a[i]==2){
			int cnt=1;
			i++;
			while(a[i]==4){
				i++;cnt++;
			}
			if(a[i]==2){
				cnt++;
				if(cnt%2==0)	{ans+=(cnt-1);i++;}
				else	ans+=(cnt-1);
			}
			else{
				ans+=cnt;
			}
		}
		else{
			if(a[i])ans++;
			i++;
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	int t = 1;
	cin>>t;
	while(t--){
		basic();
	}
}
