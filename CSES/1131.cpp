// 2024-10-23 11:49:29

#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
using namespace std;

const int N = 2e5+50;
vector<int> adj[N];
vector<int> dp1(N,0);
vector<int> dp2(N,0);
int ans = 0;
void dfs(int rt,int pr=0){
	int a=0,b=0,cnt=0;
	for(auto ch:adj[rt]){
		if(ch==pr)	continue;
		dfs(ch,rt);
		if(dp1[ch]>a){
			b=a;
			a=dp1[ch];
		}
		cnt++;
	}
	if(adj[rt].size()==1 && rt!=1){
		dp1[rt] = 0;
		dp2[rt] = 0;
	}
	else{
		dp1[rt] = a+1;
		if(a>=0 && cnt>=1)	dp2[rt]+=a+1;
		if(b>=0 && cnt>=2)	dp2[rt]+=b+1;
	}
}

void basic(){
	int n;cin>>n;
	if(n==1){
		cout<<0;return;
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		ans = max({ans,dp1[i],dp2[i]});
	}
	for(int i=1;i<=n;i++){
		cout<<i<<" "<<dp1[i]<<" "<<dp2[i]<<"\n";
	}
	cout<<ans;
}

signed main(){
	int t = 1;
	while(t--){
		basic();
	}
}