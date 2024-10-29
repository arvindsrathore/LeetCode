// 2024-10-23 10:36:43

#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
using namespace std;

const int N = 2e5+50;
vector<int> adj[N];
vector<bool> vis(N);
int ans = 0;
void dfs(int rt,int pr=0){
	for(auto ch:adj[rt]){
		if(ch==pr)	continue;
		dfs(ch,rt);
		if(!vis[ch] && !vis[rt]){
			vis[ch]=1;
			vis[rt]=1;
			ans++;
		}
	}
}
void basic(){
	int n;cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	cout<<ans;
}

signed main(){
	int t = 1;
	while(t--){
		basic();
	}
}